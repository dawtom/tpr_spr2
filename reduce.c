#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1); 
  }
  int *numbers = malloc(sizeof(int));
  int number;
  if (world_rank == 0) {
printf("\n*************************\nREDUCE\n**************************\n");

    // If we are rank 0, set the number to -1 and send it to process 1
    number = 1;
    MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    printf("\nSum is %d\n", *numbers);    

  } else if (world_rank == 1) {
    number = 2;
    MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 2) {
    number = 4;
    MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 3) {
   number = 8;
   MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

 
//   printf("Process 3 received number %d from process 0\n", number);
  }


  MPI_Finalize();
  return 0;
}
