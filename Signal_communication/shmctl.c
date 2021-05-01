#include<stdio.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void myfun(int signum)
{
	return ;
}

int main(int argv, char *argc[])
{
	int shmid;
	int key,pid;
	char *p;
	key = ftok("./shm.c", 'b');

	shmid = shmget(key, 128, IPC_CREAT | 0777);
	if(shmid <0){
		printf("creat share memory failue!\n");
		return -2;
	}
	printf("creat share memory sucess shmid is %d!\n", shmid);

	pid = fork();
	if(pid >0){
		
		signal(SIGUSR2, myfun);
		p = (char *)shmat(shmid, NULL, 0);
		if(p == NULL){
			printf("shmat function failue!\n");
			return -3;
		}
		printf("shmat function sucess!\n");
		while(1){
			printf("parent process start write share_menory:\n");
			fgets(p, 128, stdin);
			kill(pid, SIGUSR1);
			pause();
		}
	}

	if(pid == 0){
		signal(SIGUSR1, myfun);
		p = (char *)shmat(shmid,NULL,0);
		while(1){

			pause();
			printf("child process read share memory daet: %s\n", p);
			kill(getppid(),SIGUSR2);
		}
	}


	shmdt(p);
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m");
	return 0;
}
