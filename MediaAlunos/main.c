#include <stdio.h>
#include <locale.h>

char nome[30];
float nota1, nota2, media;
int i=1, q;

int main (void){
	setlocale(LC_ALL, "Portuguese");
  printf("Quantos alunos deseja cadastrar? ");
  scanf("%i", &q);
  system("clear");
  
    while(i <= q){
      printf("Nome do(a) estudante: ");
      scanf("%s", &nome);
      
      printf("Digite a 1° nota: ");
      scanf("%f", &nota1);
      
      printf("Digite a 2° nota: ");
      scanf("%f", &nota2);

      getchar();
      system("clear");
	  break;
     // media == (nota1[i] + nota2[i]) /2
      
      i++;
    } 
    return 0;
	}