#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char **argv)
{
	int rd_fd,wr_fd;
	char read_buf[128] = {0};
	int wr_ret, rd_ret;

	if(argc < 3){
		printf("cp has two parament.\n");
		return -1;
	}
	
	rd_fd=open(argv[1],O_RDONLY);
	if(rd_fd < 0){
		printf("open read file %s failue.\n", argv[1]);
		return -1;
	}
	printf("open read file %s sucess.\n", argv[1]);

	wr_fd=open(argv[2], O_WRONLY | O_TRUNC);
	if(wr_ret < 0){
		printf("open write file %s failue.\n",argv[2]);
		return -1;
	}
	printf("open write file %s sucess.\n", argv[2]);

	lseek(rd_fd,0,SEEK_SET);	
	while(1){
		//judge end
		rd_ret= read(rd_fd, read_buf, 128);
		printf("Now read %d \n",rd_fd); 
		if(rd_ret<128)
			break;
		write(wr_fd, read_buf, rd_ret);
		memset(read_buf,0,128);
	}
	write(wr_fd, read_buf, rd_ret);
	close(rd_fd);
	close(wr_fd);
	return 0;
}
