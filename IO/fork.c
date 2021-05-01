#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	pid_t pid;
	int fd[2],fd1[2];
	int ret,ret_name,fifo_file;
	int process_inter = 0;
	int b_inter = 0;
	// no name
	ret=pipe(fd);
	pipe(fd1);
	if(ret<0){
		printf("crate pipe filed!\n");
		return -1;
	}
	printf("crate pipe sucess!\n");
	
	ret_name=mkfifo("./myfifo",0777);
	if(ret_name<0){
		printf("crate fifo filed!\n");
		return -1;
	}
	printf("create fifo sucess!\n");
	fifo_file = open("./myfifo",O_RDWR);

	pid=fork();
	printf("the pid is %d\n",pid);
	if(pid == 0){
		//read(fd[0],&process_inter,1);
		read(fifo_file,&process_inter,1);
		while(process_inter==0);
		for(int i=0;i<10;i++){
			printf("this is child process i=%d\n",i);
			usleep(100);
		}
		b_inter = 1;
		write(fifo_file,&b_inter,1);
	}
	
	if(pid > 0 ){
		for(int i =0;i<10;i++){
			printf("this is farther process i= %d\n",i);
			usleep(100);
		}
		process_inter = 1;
		//write(fd[1],&process_inter,1);
		//read(fd1[0],&b_inter,1);
		write(fifo_file,&process_inter,1);
		usleep(1);	
		read(fifo_file,&b_inter,1);
		//while(b_inter==0);

	}	
	close(fd[0]);
	close(fd[1]);
	return 0;
	
}
