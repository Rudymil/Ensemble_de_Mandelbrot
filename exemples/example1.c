#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char msg[20];
	int my_rank;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	if (my_rank == 0) {
		strcpy(msg, "Hello C world !");
		MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 1 /* destinataire */, 99 /* tag */, MPI_COMM_WORLD);
	} else {
		MPI_Recv(msg, 20, MPI_CHAR, 0 /* emetteur */, 99 /* tag */, MPI_COMM_WORLD, &status);
		printf("I received %s!\n", msg);
	}
	MPI_Finalize();
}
