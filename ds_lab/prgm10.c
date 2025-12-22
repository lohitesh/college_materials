#include <stdio.h>
#include <stdlib.h>

struct node
{
      int data;
      struct node *right; 
      struct node*left;
};

struct node *root=NULL;
struct node *found;


struct node *  create(struct node *root, int  item)
{
    if (root == NULL)
    {
        root=(struct node *)malloc(sizeof(struct node));
        root->left = NULL;
        root->right = NULL;
        root->data = item;
    }
    else if (item < root->data)
         root->left = create(root->left, item);
    else if (item > root->data)
         root->right = create(root->right, item);
    else
         printf(" Duplicate Element Not Allowed !!!");
         
    return root;
}



void inorder(struct node * root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct node * root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data); 
        preorder(root->left); 
        preorder(root->right);
    }
}


void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left); 
        postorder(root->right); 
        printf(" %d ", root->data);
    }
}


struct node *search(struct node* root, int  key)
{
    if(root==NULL)                               /* Element is not found */
         return NULL;
    if(key > root->data)                       /* Search in the right sub tree. */
         return search(root->right,key);
    else if(key < root->data)          /* Search in the left sub tree. */
         return search(root->left,key);
    else                                                 /* Element Found */
          return root;
}

void main()
{
    int choice, item, n, i,key;
    while(1)
    {
        printf("\n---Binary Search Tree Operations---\n");
        printf("1-Create BST \n");
        printf("2-Inorder Traversal \n");
        printf("3-Preorder Traversal \n");
        printf("4-Postorder Traversal \n");
        printf("5-Search \n ");
        printf("6-Exit \n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: printf("\n\nBST for How Many Nodes? : ");
                         scanf("%d", &n);
                         for (i=1;i<=n;i++)
                        {
                             printf("\nEnter the Data for Nodes");
                             scanf("%d",&item);
                             root=create(root, item);
                        }
                         printf("\nBST created!!\n");
                         break;

            case 2: printf("\n BST Traversal in INORDER \n");
                          inorder(root);
                          break;

            case 3: printf("\n BST Traversal in PREORDER \n");
                          preorder(root);
                                  break;

            case 4: printf("\n BST Traversal in POSTORDER \n");
                          postorder(root);
                          break;            
                                                           
           case 5: printf("Enter node to be searched:\n"); 
                          scanf("%d",&key);
                          found=search(root,key); 
                         if(found==NULL)
                         {
                                printf("Search Unsuccessful.\n");
                                 break;
                         }
                       if(found->data==key)
                               printf("Search Successful. Node found in BST\n");                     
                        break;

         case 6: exit(0);

        default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
                
       }
   }
}
