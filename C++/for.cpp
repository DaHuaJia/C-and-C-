#include "stdio.h"
int main()
{
	int i,max,a[10];
	printf("input 10 number :\n");
	for (i=0;i<10;i++)
	    {scanf("%d",&a[i]);}
	    max=a[0];
		for (i=1;i<10;i++)
		{
			if (max<a[i])
			max=a[i];
		}
	    printf(" the max is : %d",max);    
}
