#include<sys/types.h>
#include<sys/msg.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mybuf{
	long type;
	char voltage[124];
	char ID[4];
};

int main()
{
	int msgid,ret,key;
	struct mybuf *p,sendbuf,readbuf;
	key = fotk("./shm.c", "a");
	if(key < 0){
		printf("creat key failue!\n");
		return -2;
	}

	msgid = msgget(key, IPC_CREAT | 0777);
	if(msgid < 0){
		printf("creat msg failue!\n");
		return -1;
	}
	printf("creat msg sucess msgid=%d\n", msgid);
	system("ipcs -q");
	
	p = &sendbuf;
	p->type =100;
	printf("Please input message:\n");
	fgets(p->voltage,124,stdin);

	msgsnd(msgid,p,strlen(p->voltage),0);


	p = &readbuf;
	memset(p->voltage,0,124);
	ret = msgrcv(msgid, p,124,100,0);

	printf("read buf :%s\n",p->voltage);
	while(1);

	msgctl(msgid,IPC_RMID,NULL);
	system("ipcs -q");
	return 0;
}
