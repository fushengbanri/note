#include<stdio.h>
#include<string.h>

int main()
{
	int fl;
	int cont=0;
	while((fl=fgetc(stdin)) != EOF){
		if(fl=='{'){
			cont++;
		}
		if(fl=='}'&&cont==0){
			printf("mismatching!\n");
			return 0;
		}
		if(fl=='}'&&cont!=0){
			cont--;
		}
	}
	if(cont==0)
		printf("matching!\n");
	else
		printf("mismatching!\n");
	return 0;
}
