#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MPI_ROOT_ID 0


/* globals */
int numProcs, myId, mpi_err;

void initMPI(int, char**);
void printMatrix();

int matrix[9][9];

void createMatrix(int tab[][9],int rowStartIndex,int rowEndIndex,
                            int startValue) {
	
	int i,k;
	for (i=rowStartIndex;i<rowEndIndex;i++)
		for (k=0;k<9;k++)
			tab[i][k] = startValue++;              
}

void print_rows(int tab[][9],int rowStartIndex,int rowEndIndex) {
	int i,k;
	for (i=rowStartIndex;i<rowEndIndex;i++) {
		for (k=0;k<9;k++) {
			printf("%d ", tab[i][k]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
	initMPI(argc, argv);

	if (myId == 0 ) {
		int startValue = 1;
		int rowStartIndex = 0;
		int rowEndIndex = 3;
		
		createMatrix(matrix,rowStartIndex,rowEndIndex,startValue);
	} else if (myId == 1) {
		int startValue = 28;
		int rowStartIndex = 3;
		int rowEndIndex = 6;
		
		createMatrix(matrix,rowStartIndex,rowEndIndex,startValue);
	} else {
		// myId == 2
		int startValue = 55;
		int rowStartIndex = 6;
		int rowEndIndex = 9;
		
		createMatrix(matrix,rowStartIndex,rowEndIndex,startValue);
	}
	
	MPI_Barrier(MPI_COMM_WORLD);
	if (myId == 0)
		print_rows(matrix,0,3);
	MPI_Barrier(MPI_COMM_WORLD);
	if (myId == 1)
		print_rows(matrix,3,6);
	MPI_Barrier(MPI_COMM_WORLD);
	if (myId == 2)
		print_rows(matrix,6,9);

	MPI_Finalize();
}



void initMPI(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
}
/* end helper function decfinitions */

