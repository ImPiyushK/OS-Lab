#include<stdio.h>

int main()
{
	int x,i,y,z;
	int a,b,c;
	
	x=fork();
	if(x==0)
	{	
		sleep(3); 
		printf("Child1=%d  Parent=%d\n",getpid(),getppid());
		a=fork();
		if(a==0)
		{
			printf("child of Child1=%d  Parent=%d\n",getpid(),getppid());
		}
	}
	
	else if(x>0)
	{ 
        y=fork(); 
        if (y==0) 
        { 
           sleep(3); 
           printf("Child2=%d  Parent=%d\n",getpid(),getppid());
           b=fork();
		if(b==0)
		{
			printf("child of Child2=%d   Parent=%d\n",getpid(),getppid());
		}
        } 
        else if(y>0)
        { 
            z=fork(); 
            if (z==0) 
            { 
                printf("Child3=%d  Parent=%d\n",getpid(),getppid());
                c=fork();
		if(c==0)
		{
			printf("child of Child3=%d   Parent=%d\n",getpid(),getppid());
		}
            } 
  
            else if(z>0)
            {
            	sleep(3); 
                printf("Parent=%d\n",getppid());
            } 
        }
      	}
    return 0;
} 
