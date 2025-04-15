#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

// Série de Fibonacci

int fibonacci(int n) {
  if (n == 1 || n == 2) return(1);
  else if (n>2) return(fibonacci(n-1) + fibonacci(n-2));
  else return(ERRO);
}

int main() {
  system("clear");
  int n, f;
  scanf("%d", &n);
  f = fibonacci(n);
  printf("N = %d e F = %d\n", n, f);
  
}

