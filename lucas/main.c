#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MPI_ROOT_ID 0


/* globals */
int numProcs, myId, mpi_err;
/* end globals  */

/* helper function declarations */
void initMPI(int, char**);
void printMatrix();
/* end helper function declarations */

int main(int argc, char** argv) {
	initMPI(argc, argv);

	

	MPI_Finalize();
}

/* helper function decfinitions */
void initMPI(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
}

void printMatrix() {
	int i,j;

	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}
/* end helper function decfinitions */

