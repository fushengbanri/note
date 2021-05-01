#include<stdio.h>

int main()
{
	int i,j,pr_nu;
	int count=0;
	for(i=100;i>1;i--){
		for(j=i;j>1;j--){
			if(i%j==0)
				count++;
		}
		if(count==1)
			printf("the %d is prime!\n",i);
		count=0;
	}
	printf("\n");
	return 0;
}

