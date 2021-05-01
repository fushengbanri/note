#include<stdio.h>
#include<string.h>

int main()
{
	size_t a=25;
	size_t b=1;
	size_t c=0;
	size_t d=0;
	size_t flag=sizeof(size_t);
	printf("%ld\n",flag);
	for(int i=1;i<flag;i++){
		printf("a=0x%lx\n",a);
		c=a&b;
		printf("a>>i=0x%lx\n",c);
		d=(d<<1)|c;
		a>>=1;
		if(a==0){
			printf("%d\n",i);
			d=d<<(8*4-i);
			break;
		}
		
	}
	printf("d=0x%lu\n",d);
	
	//a >>=1;
	//printf("0x%lx\n",a);
	return 0;
}
