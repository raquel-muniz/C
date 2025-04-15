#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO 0;

int main() {
  int matriz[3][3] ={
  {2, 7, 1},
  {3, 5, 8},
  {1, 6, 10}
  };

  int determinante = 0;
  determinante = determinante + matriz[0][0] * matriz[1][1] * matriz[2][2];
  determinante = determinante + matriz[0][1] * matriz[1][2] * matriz[2][0];
  determinante = determinante + matriz[0][2] * matriz[1][0] * matriz[2][1];

  determinante = determinante - matriz[2][0] * matriz[1][1] * matriz[0][2];
  determinante = determinante - matriz[2][1] * matriz[1][2] * matriz[0][0];
  determinante = determinante - matriz[2][2] * matriz[1][0] * matriz[0][1];

  printf("Determinante: %d\n", determinante);

  return 0;
  
}

