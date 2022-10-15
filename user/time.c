#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/uproc.h"
#include "user/user.h"
#define MAXARGS 16

int main(int argc, char *argv[]){
	char *newarg[MAXARGS];
	struct rusage ru;

	if(argc < 2){
		printf("Usage: time <comm> [args...]");
		exit(-1);
	}
	for(int i=0;i<argc;i++){
		newarg[i] = argv[i+1];
	}
	newarg[argc-1]=0;

	int start = uptime();
	int rc = fork();
	if(rc ==0)
		exec(newarg[0], newarg);
	wait2(0, &ru);
	int elapsed_time = uptime() - start;
	printf("elapsed time: %d ticks, cput time: %d ticks, %d% CPU\n", elapsed_time, ru.cputime, ru.cputime*100/elapsed_time);
	exit(0);

}
