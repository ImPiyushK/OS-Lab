#include<stdio.h>
#include<unistd.h>

int main()
{
	int a, b;
	
	a=fork();
	if(a==0)
	{
	    printf("child[1] --> pid = %d and ppid = %d\n",getpid(), getppid());
	    printf("Child1: Hello CHild\n");
	}
	else
	{
	   b=fork();
	   if(b==0)
	   {
	       printf("child[2] --> pid = %d and ppid = %d\n",getpid(), getppid());
	       printf("Child2: How are you.!\n");
	   }
	   else
	   {
	       sleep(3);
	       printf("Parent --> pid = %d",getpid());
	       printf("Parent: I'm Fine.!");
	   }
	}
	
	return 0;
}
