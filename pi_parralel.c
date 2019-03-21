#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double get_pi(long sqr){

    long i;
    double count = 0;
    for (i = 0; i < sqr; i++){
        double x = rand()/((double)RAND_MAX);
        double y = rand()/((double)RAND_MAX);
        if (x * x + y * y < 1.0){
            count += 1;
        }
    }
    return (4 * count)/((double)sqr);
}

int main(int argc, char** argv) {

  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  double *numbers = malloc(sizeof(double));
  double number;
  int is_scaled = atoi(argv[2]);
  long iter_num;
    if (is_scaled == 1) {
        iter_num = atol(argv[1]);
    } else {
        iter_num = atol(argv[1])/(world_size);
    }
  if (world_rank == 0) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      t1 = MPI_Wtime();
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
      t2 = MPI_Wtime();
//      double pi = *numbers/((double) world_size);
//      printf("Time: %1.6f\n", t2-t1);
//      printf("\nPi is %f\n", pi);
      FILE *fptr;
      char buffer[50];
      snprintf(buffer, sizeof(buffer), "output_%siters_%sscaled", argv[1], argv[2]);
      fptr = fopen(buffer,"a");
      fprintf(fptr, "%1.6f\n", t2-t1);
      fclose(fptr);

  } else if (world_rank == 1) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 2) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 3) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 4) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 5) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 6) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 7) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 8) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 9) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 10) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 11) {
      srand(clock());
      srand(time(NULL) + world_rank);
      MPI_Barrier(MPI_COMM_WORLD);
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  }


  MPI_Finalize();
  return 0;
}


