#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *criarArray(int Tamanho);

void main() {
  system("clear");
  int T;
  printf("Digite uma quantidade: ");
  scanf("%d", &T);
  int *meuArray = criarArray(T);
  for (int i = 0; i < T; i++) printf("%d\t", meuArray[i]);
  printf("\n");
  
}

int *criarArray(int Tamanho) {
  int *array = (int *) malloc(sizeof(int) * Tamanho);
  for (int i = 0; i < Tamanho; i++) array[i] = i;
  return array;
  
}