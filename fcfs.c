#include<stdio.h>

int main()
{
	int n;
	int k=1, i, j, min, tempat, tempid, tempbt;
	int t=0;
	printf("Enter Number of process: ");
	scanf("%d",&n);
	int ar[n][6];
	
	for(i=0 ; i<n ; i++)
	{
		printf("Enter AT and BT of %dth process: \n",(i+1));
		ar[i][0]=i+1;
		scanf("%d",&ar[i][k]);
		scanf("%d",&ar[i][k+1]);
	}
	
	//BUBBLE SORT
	for(i=0 ; i<n-1 ; i++)
	{
		for(j=0 ; j<n-i-1 ; j++)
		{
			if(ar[j][1] > ar[j+1][1])
			{
				tempat = ar[j][1];
				ar[j][1] = ar[j+1][1]; 
    				ar[j+1][1] = tempat; 
    				
    				tempid = ar[j][0];
				ar[j][0] = ar[j+1][0]; 
    				ar[j+1][0] = tempid; 
    				
    				tempbt = ar[j][2];
				ar[j][2] = ar[j+1][2]; 
    				ar[j+1][2] = tempbt; 
			}
		}
	}
	
	//CT
	t=ar[0][1]+ar[0][2];
	ar[0][3]=t;
	for(i=1 ; i<n ; i++)
	{
		t+=ar[i][2];
		ar[i][3]=t;
	}
	
	//TAT
	for(i=0 ; i<n ; i++)
	{
		ar[i][4]=ar[i][3]-ar[i][1];
	}
	
	//WT
	for(i=0 ; i<n ; i++)
	{
		ar[i][5]=ar[i][4]-ar[i][2];
	}
	
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<6 ; j++)
		{
			printf("%d\t",ar[i][j]);
		}
		printf("\n");
	}
	
}
