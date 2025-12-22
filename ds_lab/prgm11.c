#include<stdio.h>
#include<stdlib.h>

int a[10][10], n, u,v, i, j, source;
int visited[10];

void create()
{
    printf("\nEnter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=0; i<n; i++)
          for(j=0; j<n; j++)
                  scanf("%d", &a[i][j]);
}

void bfs(int source)
{
    int q[10], u, front=-1, rear=-1;
    visited[source] = 1;
    q[++rear] = source;
    printf("\nThe reachable vertices are: ");
   
    while(front<rear)
    {
             u = q[++front];
             for(v=0; v<n; v++)
          {
                if(a[u][v] == 1 && visited[v] == 0)
                {
                      q[++rear] = v;
                     visited[v] = 1;
                     printf("%d\t", v);
              }
                    }
           }
}



void dfs(int v)
{
     printf("%d\t", v);
      visited[v]=1;
     for(i=0; i<n; i++)
    {
           if(a[v][i] == 1 &&  visited[i] == 0)
                             
              	  dfs(i);
          
       }  
 
}



void main()
{
int choice;
while(1)
{
    printf("\n1.Create Graph");
    printf("\n2.BFS Traversal");
    printf("\n3.DFS Traversal");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        	case 1: create(); 
                        break;
                 
       	 case 2: for(i=0;i<n;i++)
                       visited[i]=0;
                 printf("\nEnter the source vertex : ");
                 scanf("%d", &source);
                 printf("\n Nodes that are reachable from  source node %d\n", source);
                 bfs(source);
                 break;
                
      	 case 3: for(i=0;i<n;i++)
                       visited[i]=0;
                printf("\nEnter the source vertex : ");
                scanf("%d", &source);
                printf("\n Nodes that are reachable from  source node %d\n", source);   
                for(v=0;v<n;v++)
                { 
                    if((a[source][v]==1) &&(visited[v]==0))
                              dfs(v);
                }

               break;
                
         case 4:exit(0);    

         default: printf("Invalid choice");
     }        
  }
}
