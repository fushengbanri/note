#include<stdio.h>

int increment();
int negate();

int main()
{
	int argc[3]={10,0,-10};
	int ret;
	for(int i=0;i<3;i++){
		ret=increment(argc[i]);
		printf("the increment function return %d\n",ret);
		ret=negate(argc[i]);
		printf("the negate functon return %d\n",ret);
		printf("\n\n");

	}
	return 0;       	
}
