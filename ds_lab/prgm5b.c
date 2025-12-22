#include <stdio.h>

void towerofhanoi(int, char, char, char);

void main()
{
	int n; // Number of disks
	printf("Enter number of disks\n");
	scanf("%d", &n);
	towerofhanoi(n, 'S', 'D', 'T');
}

// C recursive function to solve tower of hanoi puzzle


void towerofhanoi(int n, char source, char dest, char temp)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from %c to %c", source, dest);
		return;
	}
	towerofhanoi(n-1, source, temp, dest);
	printf("\n Move disk %d from %c to %c", n, source, dest);
	towerofhanoi(n-1, temp, dest, source);
}

