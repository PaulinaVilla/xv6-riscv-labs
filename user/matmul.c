#include "kernel/types.h"
#include "user/user.h"

#define ROWS 1000
#define COLUMNS 1000

int main(int argc, char **argv){
	
	int i,j,k,iteration,ii;
	//int echo
	double a[ROWS][COLUMNS];
	double b[ROWS][COLUMNS];
	double c[ROWS][COLUMNS];

	/*Start timing */
	int start_time = uptime();

	iteration = 1;
	if(argc==2)
		iteration = atoi(argv[1]);

	for(ii=0;ii<iteration;ii++){
		/*initialize*/
	for(i=0; i<ROWS;i++){
		for(j=0;j<COLUMNS; j++){
			a[i][j] = 3.0;
			a[i][j] = 2.0;
			c[i][j] = 0.0;
	
		}
	
	}
	if (ROWS<10)
	{
		for(i=0; i<ROWS;i++){
			for(j=0;j<COLUMNS; j++){
				printf("%p ", b[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<ROWS; i++){
			for(j=0;j<COLUMNS;j++){
				printf("%p ", b[i][j]);
			}
				printf("\n");
			}
		for(i=0;i<ROWS;i++){
			for(j=0;j<COLUMNS;j++){
				printf("%p ", c[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	/*Multiply Matrices
	 * (square)
	 */
	for(i=0; i<ROWS;i++){
		for(j=0;j<COLUMNS;j++){
			for(k=0; k<COLUMNS;k++){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	/*PRINT RESULTS*/
	if(ROWS<10){
		for(i=0;i<ROWS;i++){
			for(j=0;j<COLUMNS;j++){
				printf("%p ", c[i][j]);
			}
			printf("\n");
		}
	}
	}
	/*stop timing*/
	int end_time = uptime();
	
	/*Report Time*/
	printf("Time: %d ticks\n", end_time - start_time);

	exit(0);
}
