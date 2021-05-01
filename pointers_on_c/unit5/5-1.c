#include<stdio.h>

/*
int func(void)
{
	static int cont=1;
	return ++cont;
}

int main()
{
	int answer;
	answer = func() - func() * func();
	printf("%d\n",answer);
}

*/



int main()
{
	char str;
	printf("Plaese input a char:");
	scanf("%c",&str);
	if('A'<=str<='Z')
		str+=32;
	printf("%c\n",str);
	return 0;
}
