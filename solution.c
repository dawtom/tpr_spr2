#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    double t1, t2;
    // We are assuming at least 2 processes for this task
    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    char * text = malloc(20 * sizeof(char));
//  SENDER
    if (world_rank == 0) {
        int i;
	for (i = 0; i < 1; i++) {
           // strcat(text, "Miala baba koguta, wsadzila go do butaMiala baba koguta, wsadzila go do butaMiala baba koguta");
        	strcat(text, "m");
	}
	//printf("Sending");
        t1 = MPI_Wtime();
        MPI_Ssend(text, 20, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        //printf("Before barrier");
	MPI_Barrier(MPI_COMM_WORLD);
	//printf("After barrier");
        t2 = MPI_Wtime();
	//printf("time1: %f \ntime2: %f\n", t1, t2);
        printf("Time: %1.6f\n", t2-t1);
	FILE *fptr;
	fptr = fopen("output","a");
	fprintf(fptr, "%1.6f\n", t2-t1);
	fclose(fptr);
    } else
//    RECEIVER
    if (world_rank == 1) {
        MPI_Recv(text, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Barrier(MPI_COMM_WORLD);
        //printf("Process 1 received text from process 0\n");
    }
    MPI_Finalize();
    return 0;

}
