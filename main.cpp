#include <stdio.h>
#include <stdlib.h>
#include "ffc_version.h"
#include "mcfc_version.h"

int main(int argc, char *argv[])
{
  using ufc::cell;

  helmholtz_cell_integral_0_0 *ffc_version = new helmholtz_cell_integral_0_0();

  cell first_cell = cell();

  double ** coordinates = (double**)malloc(sizeof(double*)*3);
  coordinates[0] = (double*)malloc(sizeof(double)*2);
  coordinates[1] = (double*)malloc(sizeof(double)*2);
  coordinates[2] = (double*)malloc(sizeof(double)*2);

  coordinates[0][0] = 0.0;
  coordinates[0][1] = 0.0;
  coordinates[1][0] = 0.0;
  coordinates[1][1] = 1.0;
  coordinates[2][0] = 1.0;
  coordinates[2][1] = 0.0;
  
  first_cell.coordinates = coordinates;

  double *A = (double*)malloc(sizeof(double)*9);

  ffc_version->tabulate_tensor(A, (double**)0, first_cell);

  printf("FFC version:\n\n");
  for (int i=0; i<9; ++i)
    printf("A[%d]: %f\n", i, A[i]);
  printf("\n");

  double *B = (double*)malloc(sizeof(double*)*9);

  double mcfc_coords[6] = {0.0, 0.0, 0.0, 1.0, 1.0, 0.0};

  mcfc_version(B, 0.0, mcfc_coords);

  printf("MCFC version:\n\n");
  for (int i=0; i<9; ++i)
    printf("B[%d]: %f\n", i, B[i]);
  printf("\n");

}
