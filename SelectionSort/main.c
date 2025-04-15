#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TAMANHO 40
  // quantidade de elementos do vetor

void SelectionSort(int *Array, int Tamanho);

int main(void) {
  setlocale(LC_ALL, "Portuguese");

    int V[TAMANHO];
  srand(time(NULL));
  
  for (int i=0; i < TAMANHO; i++) V[i] = rand() % 100;
    printf("\n\nVetor original: ");
  
  for (int i=0; i < TAMANHO; i++) printf("%d, ", V[i]);
    printf("\n\n");
  
  SelectionSort(V, TAMANHO);
  
  printf("Vetor Ordenado: ");
  for (int i=0; i < TAMANHO; i++) printf("%d, ", V[i]);
  printf("\n");
  
  return 0;
  
}


void SelectionSort(int *Array,int Tamanho){
  int C = 0;
  int M = 0;
  
  for (int i=0; i < Tamanho; i++){
    int minIndex = i;
  
    for (int j = i + 1; j < Tamanho; j++){
      C++;
      if (Array[j] < Array[minIndex]){
      minIndex = j;
      }
    }

M = M + 3;
    
  int Temp = Array[minIndex];
  Array[minIndex] = Array[i];
  Array[i] = Temp;
}
  
  printf("Comparações: %d\n", C);
  printf("Movimentações: %d\n", M);
}
