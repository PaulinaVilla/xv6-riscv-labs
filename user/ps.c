#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

int
main(int argc, char ** argv)
{	static char *states[] = {
	[UNUSED]      "unused",
	[SLEEPING]    "sleep",
	[RUNNABLE]    "runnable",
	[RUNNING]     "run",
	[ZOMBIE]      "zombie", 
				}; 
	struct uproc uproc[NPROC];
	int nprocs;
	struct uproc *upr;

	/**
	 *
	 */
	nprocs= getprocs(uproc);
	if (nprocs<0)
		exit(-1);

	printf("id\tstate\tsize\tppid\tname\n");
	
	for(upr = uproc; upr < &uproc[nprocs];upr++){
		printf("%d\t%s\t%d\t%d\t%s\n", upr->pid,states[upr->state], upr->size,upr->ppid, upr->name);

	}
	exit(0);



}

