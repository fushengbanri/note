#include<stdio.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

struct server
{
	int pid;
	char buf[124];
};


void myfun(int signum)
{
	return ;
}

int main(int argv, char *argc[])
{
	int shmid;
	int key,pid;
	struct server *p;
	key = ftok("./shm.c", 'b');
	if(key < 0){
		printf("creat key failue!\n");
		return -1;
	}
	printf("creat key sucess!\n");

	shmid = shmget(key, 128, IPC_CREAT | 0777);
	if(shmid <0){
		printf("creat share memory failue!\n");
		return -2;
	}
	printf("creat share memory sucess shmid is %d!\n", shmid);



		
	signal(SIGUSR1, myfun);
	p = (struct server *)shmat(shmid, NULL, 0);
	if(p == NULL){
		printf("shmat function failue!\n");
		return -3;
	}
	printf("shmat function sucess!\n");

	p->pid = getpid();

	pause();

	pid = p->pid;

	while(1){
		printf("parent process start write share_menory:\n");
		fgets(p->buf, 128, stdin);
		kill(pid, SIGUSR2);
		pause();
	}

	shmdt(p);
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m");
	return 0;
}
