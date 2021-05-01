#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int fifo_ret,read_ret;
	char read_buf[128];

	fifo_ret=open(argv[1],O_RDONLY);

	while(1){
		read(fifo_ret,read_buf,128);
		fputs(read_buf,stdout);
	}
}
