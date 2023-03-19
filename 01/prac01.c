#include <stdio.h>
#include <mpi.h>

#define TAG_MESSAGE 1
#define TAG_DATA 2

int main(int argc, char** argv) {
  int size;
  int rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //MPI_Isend(cosaAEnviar, tamaño, tipo, recibidor, mensaje, red, almacenSolicitud)
  //MPI_Irecv(almacenDatos, tamaño, tipo, fuenteMen, mensaje, red, almacenSolicitud)
  /*Codigo que ejecuta cada nodo*/
  int send_data;
  int recv_data;
  MPI_Request recv_request;
  MPI_Request send_request;
  for (int k = 0; k < size; k++) {
    if (k != rank) {
      send_data = rank;
      MPI_Isend(&send_data, 1, MPI_INT, k, TAG_MESSAGE, MPI_COMM_WORLD, &send_request);
    } else {
      for (int j = 0; j < size; j++) {
        if (j != rank) {
          MPI_Irecv(&recv_data, 1, MPI_INT, j, TAG_MESSAGE, MPI_COMM_WORLD, &recv_request);
        }
      }
    }
  }
  MPI_Waitall(1, &recv_request, MPI_STATUSES_IGNORE);
	printf("%5i recibio mensaje %i\n", rank, recv_data);
  /**/
  MPI_Finalize();
  return 0;
}
