#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct 
{
	long msg_type;	
	char buf[128];
}msgT;


#define MSGLEN (sizeof(msgT)-sizeof(long))

int main()
{
	int msgid;
	key_t key;
	msgT msg;
	int ret;
	key = msgget(key,IPC_CREAT|0666);
	if(msgid<0)
	{
		perror("msgget");
		return 0;
	}
	msgid=msgrcv(msgid,&msg,MSGLEN,0,0);
	if(ret<0)
	{
		perror("msgrcv");
		return 0;
	}
	printf("receiv msg type = %d,buf = %s\n",(int)msg.msg_type,msg.buf);
	ret = msgctl(msgid,IPC_RMID,NULL);

}

