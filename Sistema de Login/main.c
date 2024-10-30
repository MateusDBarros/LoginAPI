#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estrutura
struct Login 
{
    char nome[25];
    char usuario[15];
    char senha[15];
    char mensagem[50];
};

//Funções
void registrar(struct Login contas[], int *numContas);
void login(struct Login contas[], int *numContas);
int main(void)
{   
    struct Login contas[100];
    int numContas = 0;
    int escolha;

    do
    {
        printf("1. Registrar.\n");
        printf("2. Login.\n");
        printf("3. Sair.\n");
        scanf("%d", &escolha);
        system("cls");
        switch (escolha)
        {
        case 1:
            registrar(contas, &numContas);
            printf("Conta criada com Sucesso!\n");
            break;
        case 2:
            login(contas, &numContas);
            break;
        case 3:
            printf("Encerrando o programa...\n");
            return 0;
            break;
        
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (escolha != 3);
    
}

void registrar(struct Login contas[], int *numContas) {
    int check = 0; //Essa variabel ira tomar conta de checar a disponibilidade do nome de usuario 0 para falso e 1 para verdadeiro

    printf("---Registrando novo usuario---\n");
    printf("Digite seu nome: ");
    scanf(" %[ ^\n]s", contas[*numContas].nome);
    do
    {
        printf("Digite o nome de usuario(sem espacos): ");
        scanf("%s", contas[*numContas].usuario);
        for (int i = 0; i < *numContas; i++) {
            if (strcmp(contas[*numContas].usuario, contas[i].usuario) == 0) {
                printf("Nome de usuario ja existente!\n");
                continue;
            }
        }
        check == 1;
    } while (check == 0);
    
    printf("Digite a senha da conta(sem espacos): ");
    scanf("%s", contas[*numContas].senha);
    (*numContas)++;
    return; //Caso a conta tenha sido criada com exito
    
}

void login(struct Login contas[], int *numContas) {
    char nome[25];
    char senha[15];
    int escolha;
    char decisao;
    printf("---Login---\n");
    printf("Digite o nome de usuario: ");
    scanf("%s", nome);
    for (int i = 0; i < *numContas; i++) {
        if (strcmp(contas[i].usuario, nome) == 0) {
            do
            {
                printf("Digite a senha da conta: ");
                scanf("%s", senha);
                if (strcmp(contas[i].senha, senha) == 0) {
                    printf("---Bem Vindo(a) %s---\n", contas[i].nome);
                    printf("O que deseja fazer hoje?\n");
                    do
                    {
                        printf("1. Conte um segredo.\n");
                        printf("2. Visualizar segredo.\n");
                        printf("3. Apagar conta.\n");
                        printf("4. Sair.\n");
                        scanf("%d", &escolha);

                        switch (escolha)
                        {
                        case 1:
                            printf("Digite a mensagem(apenas):\n");
                            scanf(" %[ ^\n]s", contas[i].mensagem);
                            break;
                        case 2:
                            if (contas[i].mensagem == NULL) {
                                printf("Aqui esta meio vazio...\n");
                            }
                            else {
                                printf("%s", contas[i].mensagem);
                            }
                            break;
                        case 3:
                            printf("Tem certeza que deseja deletar a conta?(y/n) ");
                            scanf("%c", &decisao);
                            if (decisao == 'y') {
                                for (int j = i; j < *numContas - 1; j++) {
                                    contas[j] = contas[j + 1];
                                }
                                (*numContas)--;
                                printf("Conta apagada com sucessso!\n");
                                return;
                            }
                            break;
                        case 4:
                            printf("Voltando ao menu...");
                            return;
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                        }

                    } while (escolha != 4);
                
                }
                printf("Senha incorreta!\n");
            } while (strcmp(contas[i].senha, senha) != 0);
            
        }
    }
    printf("Usuario nao encontrado\n");
    printf("Voltando ao menu principal...\n");
    return;
}
