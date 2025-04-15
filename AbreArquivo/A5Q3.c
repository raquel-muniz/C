#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *arquivo;

  arquivo = fopen("arquivo.txt", "r");

  // o r é usado para abrir o arquivo em modo de leitura

  // se o arquivo não existir, o fopen retorna NULL

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  fclose(arquivo);
  return 0;
}

