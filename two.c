#include<stdio.h>
#include<unistd.h>

int main()
{
	int a[10],n,i,sume=0,sumo=0,x;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter elements of array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	x=fork();
	if (x>0) 
	{ 
        	for (i=0;i<n;i++)
        	{ 
          	  if(i%2==0) 
              	  sume=sume + a[i]; 
        	} 
        	printf("Parent: %d\n",sume);
    	} 
  	else 
  	{ 
        	for(i=0;i<n;i++) 
        	{ 
        	    if(i%2!=0) 
        	        sumo=sumo+a[i]; 
        	} 
        	printf("Child: %d",sumo);
        } 
}
