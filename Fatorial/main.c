#include <stdio.h>
#include <stdlib.h>

#define ERRO -1 
//Define uma constante chamada ERRO

int fatorial (int N);

int main() {
  system("cls");
  int N, F;
  scanf("%d", &N);
  F =  fatorial(N);
  if (F != ERRO) printf ("O fatorial de %d é igual a %d.\n",  N, F);
  else printf("Não existe fatorial de número negativo.\n");
  
}

int fatorial (int N) {
  int resposta = 1;
  if (N>=0){
    for (int i=1; i<=N; i++) resposta = resposta * i;
      return(resposta);
  }
  
  for (int i=1; i<=N; i++) resposta = resposta * i;
  return(resposta);
  
}
