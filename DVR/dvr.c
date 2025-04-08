#include<stdio.h>
int n,cost[20][20],hop[20][20],distance[20][20];
void getcost()
{
	int i,j;
	printf("enter cost matrix\n");
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	      scanf("%d",&cost[i][j]);
	      distance[i][j]=cost[i][j];
	      hop[i][j]=j+1;
	      
	    }
	}
}
void display()
{
        int i,j;
	printf("--- ROUTING TABLE ---\n");
	for(i=0;i<n;i++)
	{
	  printf("dest\thop\tdistance\n");
	  printf("---------------------------------\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t%d\t%d\t\n",j+1,hop[i][j],distance[i][j]);
		}
		printf("\n");
	}
}
void dvr()
{
        int p=0,i,j,k;
   while(p<n-1)
      {
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(distance[i][j]>distance[i][k]+distance[k][j])
				{
				  distance[i][j]=distance[i][k]+distance[k][j];
				  hop[i][j]=hop[i][k];
				}
				
			}
		}
	}
	p++;
      }
      display();
}
int main()
{
	printf("enter no of nodes:");
	scanf("%d",&n);
	getcost();
	printf("initial table\n");
	 printf("---------------------------------\n");
	display();
	printf("final table\n");
	dvr();
	
}
