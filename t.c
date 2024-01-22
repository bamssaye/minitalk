#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int i = getpid();

	struct sigaction newDisp;
    newDisp.sa_handler = handler;
    sigemptyset(&newDisp.sa_mask);
    newDisp.sa_flags = SA_RESTART;


	
	
}
