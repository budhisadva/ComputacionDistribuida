#include <stdio.h>
#include <mpi.h>
#include <stdlib.h> //contiene rand() y srand()
#include <time.h> //contiene time() y time_t

#define TAG_MESSAGE 1
#define TAG_DATA 2

void inicializa(){
  time_t t;
  srand(time(&t));
}

int main(int argc, char** argv) {
  int size;
  int rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //MPI_Isend(cosaAEnviar, tamaño, tipo, recibidor, mensaje, red, almacenSolicitud)
  //MPI_Irecv(almacenDatos, tamaño, tipo, fuenteMen, mensaje, red, almacenSolicitud)
  /*Codigo que ejecuta cada nodo*/
  char send_data;
  int recv_data;
  MPI_Request recv_request;
  MPI_Request send_request;
  inicializa();
  int n = 1 + (rand()%2);
	if (rank == 0) {
    send_data = 'A';
    MPI_Isend(&send_data, 1, MPI_CHAR, n, TAG_MESSAGE, MPI_COMM_WORLD, &send_request);
    printf("Nodo 0 envio A a nodo %i\n", n);
  }
  if (rank == n) {
    MPI_Irecv(&recv_data, 1, MPI_CHAR, 0, TAG_MESSAGE, MPI_COMM_WORLD, &recv_request);
    int terminado;
    MPI_Waitany(1, &recv_request, &terminado, MPI_STATUSES_IGNORE);
    printf("\tNodo %i recibio mensaje %c, terminado %i\n", rank, recv_data, terminado);
  }
  /**/
  MPI_Finalize();
  return 0;
}
