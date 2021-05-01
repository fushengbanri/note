#include<stdio.h>
#include<math.h>

float square_root(int n);

int main()
{
	int n;
	float ret=1.0;
	printf("Please input a Positive number:");
	scanf("%d",&n);
	ret=square_root(n);
	printf("the %d 's square root is %f \n",n,ret);
	return 0;
}

float square_root(int n)
{
	float ret;
	float a = 1.0;
	while(1){
		ret = (a+(n/a))/2;
		if(ret==a)
			return ret;
		else
			a = ret;
		printf("the approximation value is %f\n",ret);
		
	}
}
