#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 10
#define MAX_PETS 5
#define MAX_NOME 50
#define MAX_TELEFONE 15
#define MAX_VETERINARIOS 2
#define MAX_AGENDAMENTOS 10
#define MAX_CONSULTAS 10
#define MAX_CONSULTAS_AGENDADAS 10

#define SENHA_PADRAO "patinha"


char clientes[MAX_CLIENTES][MAX_NOME];
char pets[MAX_CLIENTES][MAX_PETS][MAX_NOME];
char telefones[MAX_CLIENTES][MAX_TELEFONE];
char veterinarios[MAX_VETERINARIOS][MAX_NOME] = {"Raquel Clemente Muniz", "Fabiano"};
char agendamentos[MAX_AGENDAMENTOS][MAX_NOME][MAX_NOME];
char consultas_agendadas[MAX_CONSULTAS_AGENDADAS][MAX_NOME][MAX_NOME];


void limparTela();
void seu_primeiro_nome(int *numClientes);
void agendarBanhoTosa(int *numAgendamentos);
void realizarConsulta(int *numConsultas);
void imprimirRelatorioGeral(int numClientes, int numAgendamentos, int numConsultas);
void obterDataConsulta(char dataConsulta[], int *escolhaData);

int main() {
    char petshopNome[] = "Super_Petshop_RaquelMuniz_ES";
    char senhaDigitada[20];
    int opcao;
    int numClientes = 0;
    int numAgendamentos = 0;
    int numConsultas = 0;

    do {
        limparTela();
        printf("Digite a senha: ");
        scanf("%s", senhaDigitada);

        if (strcmp(senhaDigitada, SENHA_PADRAO) != 0) {
            printf("Senha incorreta! Tente novamente.\n");
            printf("Pressione Enter para continuar...");
            getchar();
            getchar();
        }
    } while (strcmp(senhaDigitada, SENHA_PADRAO) != 0);

    while (1) {
        limparTela();

        printf("%s\n", petshopNome);
        printf("\n------------ MENU ------------\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Agendar BANHO ou TOSA\n");
        printf("3 - CONSULTA\n");
        printf("4 - IMPRIMIR RELATORIO GERAL\n");
        printf("5 - SAIR\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                seu_primeiro_nome(&numClientes);
                break;
            case 2:
                agendarBanhoTosa(&numAgendamentos);
                break;
            case 3:
                realizarConsulta(&numConsultas);
                break;
            case 4:
                imprimirRelatorioGeral(numClientes, numAgendamentos, numConsultas);
                break;
            case 5:
                printf("Volte sempre ao %s\n", petshopNome);
                exit(0);
            default:
                printf("Opcao incorreta. Pressione Enter para continuar...");
                getchar();  
                getchar();  
                break;
        }
    }

    return 0;
}


void limparTela() {
    system("clear");
}

void seu_primeiro_nome(int *numClientes) {
    if (*numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    printf("------------ CADASTRO DE CLIENTE ------------\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[*numClientes]);

    int numPets;
    printf("Quantos pets deseja cadastrar para %s? ", clientes[*numClientes]);
    scanf("%d", &numPets);

    if (numPets > 0 && numPets <= MAX_PETS) {
        for (int i = 0; i < numPets; ++i) {
            printf("Digite o nome do pet %d: ", i + 1);
            scanf("%s", pets[*numClientes][i]);
        }
    }
    else {
        printf("Numero invalido de pets.\n");
    }

    printf("Digite o telefone: ");
    scanf("%s", telefones[*numClientes]);

    (*numClientes)++;
    printf("Cadastro realizado com sucesso!\n");
    limparTela();
}

void agendarBanhoTosa(int *numAgendamentos) {
    if (*numAgendamentos >= MAX_AGENDAMENTOS) {
        printf("Limite de agendamentos atingido.\n");
        return;
    }

    printf("------------ AGENDAMENTO DE BANHO ou TOSA ------------\n");

    printf("Selecione o cliente para agendar: \n");
    for (int i = 0; i < MAX_CLIENTES; ++i) {
        printf("%d - %s\n", i + 1, clientes[i]);
    }
    int escolhaCliente;
    printf("Escolha o numero correspondente ao cliente: ");
    scanf("%d", &escolhaCliente);
    escolhaCliente--;

    if (escolhaCliente < 0 || escolhaCliente >= MAX_CLIENTES) {
        printf("Escolha de cliente invalida.\n");
        return;
    }

    printf("Selecione o pet para agendar: \n");
    for (int i = 0; i < MAX_PETS; ++i) {
        if (strlen(pets[escolhaCliente][i]) > 0) {
            printf("%d - %s\n", i + 1, pets[escolhaCliente][i]);
        }
    }
    int escolhaPet;
    printf("Escolha o numero correspondente ao pet: ");
    scanf("%d", &escolhaPet);
    escolhaPet--;

    if (escolhaPet < 0 || escolhaPet >= MAX_PETS || strlen(pets[escolhaCliente][escolhaPet]) == 0) {
        printf("Escolha de pet invalida.\n");
        return;
    }

    printf("Nome do pet: %s\n", pets[escolhaCliente][escolhaPet]);
    printf("Escolha uma opcao:\n");
    printf("1 - Banho\n");
    printf("2 - Tosa\n");
    printf("3 - Banho e Tosa\n");

    int escolhaOpcao;
    printf("Escolha o numero correspondente a opcao desejada: ");
    scanf("%d", &escolhaOpcao);

    (*numAgendamentos)++;
    printf("Agendamento de BANHO ou TOSA realizado com sucesso!\n");
    limparTela();
}

void realizarConsulta(int *numConsultas) {
    if (*numConsultas >= MAX_CONSULTAS_AGENDADAS) {
        printf("Limite de consultas agendadas atingido.\n");
        return;
    }

    printf("------------ AGENDAMENTO DE CONSULTA ------------\n");

    char dataConsulta[20];
    int escolhaData;
    obterDataConsulta(dataConsulta, &escolhaData);

    printf("Escolha a opcao para agendar o dia:\n");
    printf("1 - Manha\n");
    printf("2 - Tarde\n");
    int escolhaDia;
    printf("Escolha o numero correspondente ao periodo desejado: ");
    scanf("%d", &escolhaDia);

    printf("Selecione o cliente para agendar consulta: \n");
    for (int i = 0; i < MAX_CLIENTES; ++i) {
        printf("%d - %s\n", i + 1, clientes[i]);
    }
    int escolhaCliente;
    printf("Escolha o numero correspondente ao cliente: ");
    scanf("%d", &escolhaCliente);
    escolhaCliente--;

    printf("Escolha um veterinario:\n");
    for (int i = 0; i < MAX_VETERINARIOS; ++i) {
        printf("%d - %s\n", i + 1, veterinarios[i]);
    }
    int escolhaVeterinario;
    printf("Escolha o numero correspondente ao veterinario: ");
    scanf("%d", &escolhaVeterinario);
    escolhaVeterinario--;

    strcpy(consultas_agendadas[*numConsultas][0], dataConsulta);
    strcpy(consultas_agendadas[*numConsultas][1], clientes[escolhaCliente]);
    strcpy(consultas_agendadas[*numConsultas][2], veterinarios[escolhaVeterinario]);

    (*numConsultas)++;
    printf("Consulta agendada com sucesso!\n");
    limparTela();
}

void obterDataConsulta(char dataConsulta[], int *escolhaData) {
    printf("Escolha uma data:\n");
    printf("1 - Segunda-feira\n");
    printf("2 - Quinta-feira\n");
    printf("Escolha o numero correspondente ao dia: ");
    scanf("%d", escolhaData);

    if (*escolhaData == 1) {
        strcpy(dataConsulta, "Segunda-feira");
    }
    else if (*escolhaData == 2) {
        strcpy(dataConsulta, "Quinta-feira");
    } 
    else {
        printf("Opcao incorreta.\n");
        printf("Pressione Enter para continuar...");
        getchar();  
        getchar();  
        limparTela();
        obterDataConsulta(dataConsulta, escolhaData);
    }
}

void imprimirConsultasAgendadas(int numConsultas) {
    printf("\nConsultas agendadas:\n");
    for (int i = 0; i < numConsultas; ++i) {
        printf("Data: %s, Cliente: %s, Veterinario: %s\n", consultas_agendadas[i][0], consultas_agendadas[i][1], consultas_agendadas[i][2]);
    }
}

void imprimirRelatorioGeral(int numClientes, int numAgendamentos, int numConsultas) {
    printf("------------ RELATORIO GERAL ------------\n");

    printf("Clientes cadastrados:\n");
    for (int i = 0; i < numClientes; ++i) {
        printf("%s\n", clientes[i]);
    }

    printf("\nAgendamentos realizados:\n");
    for (int i = 0; i < numAgendamentos; ++i) {
        printf("Pet: %s, Tipo: %s\n", agendamentos[i][0], agendamentos[i][1]);
    }

    printf("\nConsultas agendadas:\n");
    for (int i = 0; i < numConsultas; ++i) {
        printf("Data: %s, Cliente: %s, Veterinario: %s\n", consultas_agendadas[i][0], consultas_agendadas[i][1], consultas_agendadas[i][2]);
        imprimirConsultasAgendadas(numConsultas);
    }

    printf("\nPressione Enter para continuar...");
    getchar();  
    getchar();  
    limparTela();
}