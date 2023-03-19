#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
  //Cada proceso se identifica por un número llamado rank
  int size, rank;
  printf("%i\n", argc);
  printf("%s\n", argv[0]);
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  printf("Hola mundo (size = %i, rank = %i)\n", size, rank);
  /*
  */
  // Termina la conección MPI, bloquea la ejecución hasta que todos
  // los procesos terminen.
	MPI_Finalize();
  return 0;
}
