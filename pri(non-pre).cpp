#include <stdio.h>
#include <stdlib.h>
#define totalprocess 5
struct process
{
	int at,bt,pr,pno;
};
struct process proc[50];
typedef int (*compfn)(const void*, const void*);
int n;
int comp(struct process *a, struct process *b)
{
	if(a->at == b->at)
	{
		if(a->pr<b->pr)
			return 1;
		else
			return 0;
	}
	else
	{
		if(a->at<b->at)
			return 1;
		else
			return 0;
	}
}
void get_wt_time(int wt[])
{
	int service[50], i;
	service[0]=0;
	wt[0]=0;
	for(i=1;i<totalprocess;i++)
	{
		service[i]=proc[i-1].bt+service[i-1];
		wt[i]=service[i]-proc[i].at+1;
		if(wt[i]<0)
		{
		wt[i]=0;
		}
	}
}
void get_tat_time(int tat[],int wt[])
{
	int i;
	for(i=0;i<totalprocess;i++)
	{
		tat[i]=proc[i].bt+wt[i];
	}
}
void findgc()
{
	int wt[50],tat[50], stime[50],ctime[50], i;
	double wavg=0,tavg=0;
	get_wt_time(wt);
	get_tat_time(tat,wt);
	stime[0]=1;
	ctime[0]=stime[0]+tat[0];
	for(i=1;i<totalprocess;i++)
	{
		stime[i]=ctime[i-1];
		ctime[i]=stime[i]+tat[i]-wt[i];
	}
	printf("Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n");
	for(int i=0;i<totalprocess;i++)
	{
		wavg += wt[i];
		tavg += tat[i];
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pno,stime[i],ctime[i],tat[i],wt[i]);
	}

	printf("Average waiting time is : ");
	printf("%f\n",wavg/(float)totalprocess);
	printf("Average turnaround time : ");
	printf("%f\n",tavg/(float)totalprocess);
}
int main()
{
	int arrivaltime[10],bursttime[10],priority[10], n, i, x;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter Arrival Time, Burst Time & Priority:\n");
	printf("Process  Arrival Time\tBurst Time\tPriority\n");
	for(x=0;x<totalprocess;x++)
	{
	     printf("P[%d]\t\t",x+1);
	     scanf("%d", &arrivaltime[x]);
	     scanf("%d", &bursttime[x]);
		scanf("%d", &priority[x]);
	}
	for(i=0;i<totalprocess;i++)
	{
		proc[i].at=arrivaltime[i];
		proc[i].bt=bursttime[i];
		proc[i].pr=priority[i];
		proc[i].pno=i+1;
	}
	qsort(proc,totalprocess,sizeof(proc),(compfn)comp);
	findgc();
	return 0;
}
