#include<stdio.h>
#include <unistd.h> 
int main()
{
	int n,sumo=0,sume=0,i,a;
	printf("Enter a limit: ");
	scanf("%d",&n);
	a=fork();
		printf("a= %d",a);
	if(a>0)
	{
		for(i=0;i<=n;i+=2)
			sume+=i;
		printf("parent process: %d\n",sume);	
	}
	else
	{
		for(i=1;i<=n;i+=2)
			sumo+=i;
		printf("child process: %d\n",sumo);
	}
}
