#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int fifo_ret,write_ret;
	char write_buf[128];
	fifo_ret = open(argv[1],O_RDWR);
	if(fifo_ret<0){
		printf("Open fifo failure!\n");
		return -1;
	}
	printf("Open fifo sucess!\n");
	
	fgets(write_buf,128,stdin);

	write_ret=write(fifo_ret,write_buf,10);
	if(write_ret<0){
		printf("write failure\n");
		return -1;
	}
	printf("write sucess!\n");
	return 0;
}
