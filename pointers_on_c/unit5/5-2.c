#include<stdio.h>
#include<string.h>

char *my_encrypt();

int main()
{
	char str[128], encrypted[128];
	printf("Plase input your string:");
	fgets(str,128,stdin);
	my_encrypt(str,encrypted);
	printf("The encrypt is:%s\n", encrypted);
	return 0;
}

char *my_encrypt(const char *str, char *encrypted)
{
	char *encrypt = encrypted;
	while(*str !='\0'){
		if(((*str>='A')&&(*str<='Z'))||((*str>='a')&&(*str<='z')))
			*encrypt++ = (*str++)+13;
		else 
			*encrypt++ = *str++;
	}
	*encrypt++ = '\0';
	return encrypt;
}
