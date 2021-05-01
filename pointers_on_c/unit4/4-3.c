#include<stdio.h>

int	judge(int a, int b, int c);
char *what_triangle();

int main()
{
	int a,b,c;
	char *ret;
	while(1){
		printf("Please input three number for the triangle:");
		scanf("%d,%d,%d",&a,&b,&c);
		if(judge(a,b,c)==-1){
			printf("You inputs number isn't triangle!Pleae input again:\n");
		}
		else{
			printf("You input's number is triangle!\n");
			break;
		}
	}

	ret = what_triangle(a,b,c);
	printf("the triangle is %s\n", ret);
	return 0;
}


char *what_triangle(int a, int b, int c)
{
	if(a==b&&b==c)
		return "Equilateral triangle";
	else if(a==b || a==c || b==c)
		return "an isosceles triangle";
	else
		return "ordinary triangle";
}

int judge(int a, int b, int c)
{
	if((a+b)>c && (a+c)>b && (b+c)>a)
		return 0;
	else
		return -1;
}
