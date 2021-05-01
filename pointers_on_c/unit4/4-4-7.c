#include<stdio.h>
#include<string.h>


void copy_n();
int str_len();
int chose_str();
int substr(char dst[], char stc[], int start, int len);
void deblank();

int main()
{
	int ret;
	char str[]="The strings may not overlap";
	char str2[]="The  strings   may  not overlap";
	char dst[128];
	
	chose_str();
	printf("-----------------------------------------\n");
	
	ret = substr(dst,str,5,3);
	printf("%d\n",ret);
	printf("%s\n", dst);
	printf("---------------------------------------------\n");
	deblank(str2);
	printf("%s\n",str2);
	return 0;
}


void deblank(char string[])
{
	int cont=0,j;
	char str;
	printf("%s\n",string);
	for(int i=0;string[i]!='\0';i++){
		if(string[i]==' '&&string[i-1]==' ')
			cont++;
		if(cont==1){
			for(j=i;string[j]!='\0';j++)
				string[j-1]=string[j];
			string[j-1]='\0';
			i--;
			cont=0;
		}
	}

			
}


int substr(char dst[], char stc[],int start, int len)
{
	if(start>str_len(stc) || start <0 || len < 0){
		dst = '\0';
		return 0;
	}
	for(int i=start;i<(len+start);i++)
		*dst++=stc[i];
	*dst++='\0';
	return str_len(dst);

}

int chose_str()
{
	FILE *fp;
	int i=0,cont=0;
	
	char dst[128],str[128];
	fp=fopen("./4-5.c","rb");
	if(fp==NULL){
		printf("open file failue!\n");
		return -1;
	}
	while(fgets(dst,128,fp)!=NULL){
		if(*str==*dst && i>0){
			cont++;
			if(cont==1)
				printf("%s", str);
		}
		else if(i==0)
			cont=0;
		else
			cont=0;
		//strcpy(str,dst);
		copy_n(str,dst,str_len(dst));
		i++;
	}
	
}



void copy_n(char str[], const char dst[], int n)
{
	
	while((*str++ = *dst++) != '\0' && n--);
	while(n--)
		*str++='\0';
}

int str_len(char *dst)
{
	int cont=1;
	while(*dst++!='\0')
		cont++;
	return cont;
}
