#include<stdio.h>
#include<unistd.h>

int main()
{
	char s1[50], s2[50];
	int x, l,i,j,l1,l2;
	int count, count1;
	printf("Enter String 1: ");
	gets(s1);
	printf("Enter String 2: ");
	gets(s2);
	for (l1 = 0; s1[l1] != '\0'; l1++);
	for (l2 = 0; s2[l2] != '\0'; l2++);
	for (l = 0; s2[l] != '\0'; l++);
	
	x=fork();
	
	if(x>0)
	{
		for (i=0,j=0 ; s1[i]!='\0' && s2[j]!='\0' ; i++)
    		{
        		if(s1[i]==s2[j])
        		{
            			j++;
        		}
        		else
        		{
            			j=0;
        		}
    		}
    		if(j==l)
    		printf("Parent %d",(i-j+1));
    		else
    		printf("Not Found");
	}
	else if(x==0)
	{
	        for (i=0; i<=l1;)
		{
			j=0;
		        count=0;
		        while ((s1[i] == s2[j]))
		        {
		       	 	if(i<l1)
		        	{
		           	 count++;
		            	 i++;
		         	}   
		            j++;
			}
			if (count==l2)
			{
				
				count1++;                                   
				count=0;
			}
			else
				i++;
		}
		printf("Child: %d",count1);
	}
}



