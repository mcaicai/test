#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


typedef void (*sighandler_t)(int);

sighandler_t oldact;

void handle(int sig)
{
	printf("I cath the SIGINT \n");
	signal(SIGINT ,oldact);
}

int main()
{
	oldact = signal(SIGINT,handle);
	while(1)
	{
		sleep(1);
	}


}
