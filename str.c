#include "./lib/mylist.h"

struct node
{
	char date[124];
	int i;
}*p;


//
int main()
{
	p->date="h";
	p->i = 5;
	printf("%s", p->date);
}
