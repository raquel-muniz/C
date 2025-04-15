#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int main(void) {
    char senha[3]; 
  
 //(senha correta: “123”)
  
    printf("Digite a senha: ");
    scanf("%3s", senha); 
    system("break");
    system("clear");
  
// “ERRO DE SENHA”, digite novamente.
// “SENHA CORRETA”
  
    if (strcmp(senha, "123") == 0) {
        printf("Senha correta!! Pressione ENTER para continuar. \n");
        system("break");
      system("clear");
    } else {
        while (strcmp(senha, "123") != 0) {
            printf("Senha incorreta! \nDigite novamente: ");
            scanf("%3s", senha);
          system("clear");
        } if (strcmp(senha, "123") == 0) {
        printf("Senha correta!! Pressione ENTER para continuar. \n");
        system("break");
      system("clear");
        }
    }

  printf("Etapa 2");
  
  //  Usuário tem um menu de 3 opções
  
  //  1 - Cadastro cliente (2pts)
  //  Será cadastrado NOME do cliente
  //  Cadastrado o Telefone
  //  Cadastrado o Endereço
  //  2 - Compra de Computadores (2pts)
  //  Aparece 3 opções de Computadores para escolher 1
  //  Pede a cor do Gabinete
  //  Escolhe a forma de pagar
  //  3 - Compra de periféricos (2pts)
  //  Escolhe o nome do acessório
  //  Escolhe a quantidade
  //  4 – SAIR DO PROGRAMA (1pto)
  //  Ao sair, surge a mensagem (PROGRAMA FINALIZADO!)
  //  Quando o cliente finalizar uma das 3 primeiras opções, o programa volta para o menu principal.
  
    return 0;
}