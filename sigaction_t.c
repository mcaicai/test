#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <linux/posix_types.h>


typedef void (*sighandler_t)(int);

sighandler_t oldact;

void handle(int sig)
{
	if(sig==SIGINT){
	printf("I cath the SIGINT \n");
//	signal(SIGINT ,oldact);
	}else if(sig==SIGALRM)
	{
		printf("second timer \n");
		alarm(1);
	}
	

}

void mytimer(int sig)
{
	
	
}

int main()
{
//	oldact = signal(SIGINT,handle);
	struct sigaction act;
	act.sa_handler=handle;
	act.sa_flags =0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT,&act,NULL);
	alarm(1);
	sigaction(SIGALRM,&act,NULL);
	

	while(1)
	{
		sleep(1);
	}


}
