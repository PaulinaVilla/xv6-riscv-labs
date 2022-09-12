#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
	int counter;
	counter = atoi(argv[1]);
	if(argv[1]){
		sleep(counter);
		exit(0);
	}else{
		printf("Error: No argument\n");
		exit(0);
	}

	}

