/* Question 24-- Consider following and Generate a solution in C to find whether the system is in safe state or not?

    Available       Processes       Allocation                 Max
 A   B   C   D                   A    B    C    D        A    B    C    D
 1   5   2   0         P0        0    0    1    2        0    0    1    2
                       P1        1    0    0    0        1    7    5    0 
                       P2        1    3    5    4        2    3    5    6
                       P3        0    6    3    2        0    6    5    2
                       P4        0    0    1    4        0    6    5    6                                                                       */


#include<stdio.h>
int main()
{
	int num;
	int n;
	int i,j,k,c,c1;
	int avail[20],arr[10];
	int need[20][20],alloc[20][20],max[20][20];
	
	printf("\nEnter number of processes :");
	scanf("%d",&num);
	
	printf("\nEnter the number of resources available :");
	scanf("%d",&n); 
	
	printf("\nEnter instances for resources(Press enter after entering each integer value) :\n");
	for(i=0;i<n;i++)
	{
		printf("R%d    ",i+1);
		scanf("%d",&avail[i]);
	}
	printf("\n Enter allocation matrix(INTEGER) with one space after each integer  \n");   //Allocation Matrix
	printf("\n       A B C D \n");            //For pretty formatting output
	for(i=0;i<num;i++)
	{
		printf("p%d     ",    i);          arr[i]=0;       //to print the process number
		for(j=0;j<n;j++)
		{
			scanf("%d",    &alloc[i][j]);
		}
	}
	printf("\n Enter MAX matrix(INTEGER) with one space after each integer  \n");        //MAX Matrix
	printf("\n       A B C D \n");           //For pretty formatting output
	for(i=0;i<num;i++)                                 //Sorting the process
	{
		printf("p%d     ",    i);                          //to print the process number
		for(j=0;j<n;j++)                                   //Sorting the process
		{
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<num;i++)                                 //Sorting the process
	{
		printf("\np%d\t",i) ;
		for(j=0;j<n;j++)                                   //Sorting the process
		{
			need[i][j]=max[i][j]-alloc[i][j];                 //Need= maximum resources - currently allocated resources
			printf("\t%d",need[i][j]);
		}
	}
	k=0;     c1=0;
	printf("\n\n");
	while(k<15)
	{
		for(i=0;i<num;i++)                                 //Sorting the process
		{
			c=0;
			for(j=0;j<n;j++)                                   //Sorting the process
			{
				if(arr[i]==1) break;
				if(need[i][j]<=avail[j])
				{
					c++;
				}
				if(c==n)
				{
					for(j=0;j<n;j++)
					{
						avail[j]+=alloc[i][j];
					}
					printf("p%d\t ->",i);  arr[i]=1;     c1++;
				}
			}
		}
		k++;
	}
}
