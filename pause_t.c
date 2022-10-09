#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void handle(int sig)
{

	printf("I get sig = %d\n",sig);
}

void mytask()
{
	printf("My task start\n");
	sleep(3);
	printf("my task end\n");
}

int main()
{
	struct sigaction act;
	act.sa_handler = handle;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT,&act,NULL);
	sigaction(SIGHUP,&act,NULL);
	sigset_t set;
	sigaddset(&set,SIGHUP);
	sigaddset(&set,SIGINT);
	pause();
	while(1)
	{
		sigprocmask(SIG_BLOCK,&set,NULL);
		mytask();
		sigprocmask(SIG_UNBLOCK,&set,NULL);
		pause();
	}
	printf("after pause\n");
	while(1)
	{
		sleep(1);
	}
}


