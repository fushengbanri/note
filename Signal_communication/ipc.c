#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
	int shmid;
	int key;
	char *p;
	key=ftok("./shm.c", 'a');
	if(key<0){
		printf("create ftok key failure!\n");
		return -1;
	}
	printf("create ftok key successful!\n");

	shmid = shmget(key, 128, IPC_CREAT | 0777);
	if(shmid==-1){
		printf("crate shm failure!\n");
		return -2;
	}
	printf("crate shm sucess!\n");
	
	//system("ipcs -m");
	shmctl(shmid, IPC_STAT, stdout);
	p=(char *)shmat(shmid, NULL, 0);

	if(p == NULL){
		printf("shmat function failure!\n");
		return -3;
	}
	printf("shmat function success!\n");
	
	//write share memory
	
	fgets(p,128,stdin);


	//read share menory
	
	printf("read for share memory:%s\n", p);

	shmctl(shmid, IPC_RMID,0);
	return 0;
}
