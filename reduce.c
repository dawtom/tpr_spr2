#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

double get_pi();

int main(int argc, char** argv) {

  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  double *numbers = malloc(sizeof(double));
  double number;
  int iter_num = atoi(argv[1]);
  if (world_rank == 0) {
      number = get_pi(iter_num);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
      double pi = *numbers/((double) world_size);
      printf("\nPi is %f\n", pi);

  } else if (world_rank == 1) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 2) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 3) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 4) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 5) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 6) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 7) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 8) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 9) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 10) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  } else if (world_rank == 11) {
      number = get_pi(iter_num);
      printf("\nPi in %d is %f\n", world_rank, number);
      MPI_Reduce(&number, numbers, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  }


  MPI_Finalize();
  return 0;
}

double get_pi(sqr){
    srand(clock());
    srand(time(NULL));
  double i;
  double count = 0;
  for (i = 0; i < sqr; i++){
    double x = rand()/((double)RAND_MAX);
    double y = rand()/((double)RAND_MAX);
    if (x * x + y * y < 1.0){
      count += 1;
    }
  }
  return (4 * count)/(sqr);
}
