#include<stdio.h>
int main()
{
	int n,se,i,j,re=1,ik=0,cnt=0,qt,t;
	float ts=0,wts=0;
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	int a[n][6],b[n];
	printf("Enter values : \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter a[%d][%d] = ",j+1,i+1);
			scanf("%d",&a[j][i]);
		}
	}
	printf("\n\nEnter quantum time :- ");
	scanf("%d",&qt);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(a[j][0]>a[j+1][0])
			{
				t=a[j+1][0];
				a[j+1][0]=a[j][0];
				a[j][0]=t;

				t=a[j+1][1];
				a[j+1][1]=a[j][1];
				a[j][1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		b[i]=a[i][1];
		a[i][5]=0;
	}
	j=0;
	se=0;
	while(j<n)
	{
		ik=-1;
		re=se+1;
		for(i=0;i<n;i++)
		{
			if(a[i][0]<=cnt)
			{
				if(a[i][5]<re&&a[i][5]!=-1)
				{
					ik=i;
					re=a[i][5];
				}

			}
		}
		if(ik!=-1)
		{
			if(a[ik][1]<=qt) cnt+=a[ik][1];
			else cnt+=qt;

			for(i=ik+1;i<n;i++)
			{
				if(a[i][5]!=0) continue;
				else if(a[i][0]<=cnt) a[i][5]=++se;
			}
			a[ik][1]-=qt;
			if(a[ik][1]<=0)
			{
				a[ik][2]=cnt;
				a[ik][5]=-1;
				j++;
			}
			else
			{
				a[ik][5]=++se;
			}

		}
		else
		cnt++;
	}
	printf("\n\n===================================\n");
	printf("A.T    B.T    E.A.T    T.A.T    W.T\n");
	printf("===================================\n");
	for(i=0;i<n;i++)
	{
		a[i][3]=a[i][2]-a[i][0];
		a[i][4]=a[i][3]-b[i];
		ts+=a[i][3];
		wts+=a[i][4];
		printf("%d     %d      %d        %d          %d\n",a[i][0],b[i],a[i][2],a[i][3],a[i][4]);
	}

	printf("\navg tat = %f\navg wt = %f",ts/n,wts/n);
}
