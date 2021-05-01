#include<stdio.h>

int main(int argc, char **argv)
{
	
	FILE *fp;
	char buf[128]={0};
	fp = fopen(argv[1],"r");
	if(fp<0){
		printf("Open %s file failue.\n",argv[1]);
		return -1;
	}
	printf("open %s file sucess.\n", argv[1]);
	while(1){
		fgets(buf,128,fp);
		if(feof(fp)>0)
			break;
		fputs(buf,stdout);
	}
	fclose(fp);
	return 0;
}
