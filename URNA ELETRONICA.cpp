//                                         NOME DA DUPLA: 
//                                         GUILHERME ABTIBOL LIRA VALENTE // MATRICULA: 2402970
//                                         CAU� MEDEIROS DE OLIVEIRA      // MATRICULA: 2407822 
//                                         TURMA: ENGS241N01 (ENGENHARIA DE SOFTWARE); TURNO: NOTURNO; 
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 100 
#define SENHA "1234" // Senha para acessar o menu t�cnico

int numerosPrefeito[MAX_CANDIDATOS];
int numerosVereador[MAX_CANDIDATOS];
char nomesPrefeito[MAX_CANDIDATOS][50];
char nomesVereador[MAX_CANDIDATOS][50];
int temposdeVidaPrefeito[MAX_CANDIDATOS];
int temposdeVidaVereador[MAX_CANDIDATOS];
int votosPrefeito[MAX_CANDIDATOS];
int votosVereador[MAX_CANDIDATOS];
int numCandidatosPrefeito = 0;
int numCandidatosVereador = 0;
int numVotos = 0;
int quantVotosBranco = 0;
int votacaoAtiva = 0;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao, numero, encontrou, i, tipoVoto, tipoEleicao;
    char senha[10];
    char titulo[13]; // Vari�vel para armazenar o t�tulo de eleitor com 12 d�gitos
    int tituloUsado = 0;

    while (1) {
        printf("\t\t\t\t _______________________\n");
        printf("\t\t\t\t|                        |\n");
        printf("\t\t\t\t| **  URNA ELETRONICA ** |\n");
        printf("\t\t\t\t _______________________\n");

        if (!votacaoAtiva) {
            printf("\t\t\t\t ** Ol�, Administrador. ** ");
            printf("\t\t\t\t                           \n");
            printf("\t\t\t\t _______________________\n");
            printf("\t\t\t\t                        \n");
            printf("\t\t\t\t  1. Menu T�cnico\n");
            printf("\t\t\t\t  0. Sair\n");
            printf("\t\t\t\t _______________________\n");
            printf("\t\t\t\t                           \n");
        } else {
            printf("\t\t\t\t  2. Votar\n"); // Op��o de votar s� aparece ap�s a vota��o ser iniciada
            printf("\t\t\t\t  9. Encerrar Vota��o (Apenas Administrador)\n");
        }

        printf("\t\t\t\t    Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        if (opcao == 1 && !votacaoAtiva) {
            printf("\t\t\t   Digite a senha para o menu t�cnico: ");
            scanf("%s", senha);
            system("cls");

            if (strcmp(senha, SENHA) == 0) {
                printf("Acesso Liberado\n");

                int opcaoTecnica;
                while (1) {
                    printf("\t\t\t\t ___________________________\n");
                    printf("\t\t\t\t|                           |\n");
                    printf("\t\t\t\t|      MENU TECNICO         |\n");
                    printf("\t\t\t\t ___________________________\n");
                    printf("\t\t\t\t|                           |\n");
                    printf("\t\t\t\t|   1. Adicionar Candidato  |\n");
                    printf("\t\t\t\t|   2. Iniciar Vota��o      |\n");
                    printf("\t\t\t\t|   3. Resultado            |\n");
                    printf("\t\t\t\t|   0. Voltar               |\n");
                    printf("\t\t\t\t ___________________________\n");
                    printf("\t\t\t\t|                           |\n");
                    printf("\t\t\t\t    Escolha uma op��o: ");
                    scanf("%d", &opcaoTecnica);
                    getchar(); // Limpa o buffer de entrada

                    if (opcaoTecnica == 1) {
                        printf("\t\t\t\t                          \n");
                        printf("\t\t\t  Tipo de candidato:\n");
                        printf("\t\t\t  1. Prefeito\n");
                        printf("\t\t\t  2. Vereador\n");
                        printf("\t\t\t  Escolha a op��o: ");
                        scanf("%d", &tipoEleicao);
                        
                        if (tipoEleicao == 1) { // Adicionar Prefeito
                            printf("\t\t\t  Numero do candidato: ");
                            scanf("%d", &numerosPrefeito[numCandidatosPrefeito]);
                            printf("\t\t\t  Nome do candidato: ");
                            scanf("%49s", nomesPrefeito[numCandidatosPrefeito]);
                            

                            printf("\t\t\t  T�tulo de eleitor (12 d�gitos): ");
                            int valido = 0;
                            while (!valido) {
                                scanf("%s", titulo);
                                
                                if (strlen(titulo) == 12) {
                                    valido = 1;
                                    for (i = 0; i < 12; i++) {
                                        if (titulo[i] < '0' || titulo[i] > '9') {
                                            valido = 0;
                                            printf("Erro: O t�tulo de eleitor deve conter apenas n�meros!\n");
                                            break;
                                        }
                                    }
                                } else {
                                    printf("Erro: O t�tulo de eleitor deve ter 12 d�gitos!\n");
                                }
                                
                                if (!valido) {
                                    printf("\t\t\t  T�tulo de eleitor inv�lido. Digite novamente: ");
                                }
                            }

                            printf("\t\t\t  Data de nascimento (dd/mm/aaaa): ");
                            int dia, mes, ano;
                            scanf("%d/%d/%d", &dia, &mes, &ano);
                            temposdeVidaPrefeito[numCandidatosPrefeito] = ano * 10000 + mes * 100 + dia;
                            votosPrefeito[numCandidatosPrefeito] = 0;
                            numCandidatosPrefeito++;
                        } else if (tipoEleicao == 2) { // Adicionar Vereador
                            printf("\t\t\t  Numero do candidato: ");
                            scanf("%d", &numerosVereador[numCandidatosVereador]);
                            printf("\t\t\t  Nome do candidato: ");
                            scanf("%49s", nomesVereador[numCandidatosVereador]);
                            

                            printf("\t\t\t  T�tulo de eleitor (12 d�gitos): ");
                            int valido = 0;
                            while (!valido) {
                                scanf("%s", titulo);
                                
                                if (strlen(titulo) == 12) {
                                    valido = 1;
                                    for (i = 0; i < 12; i++) {
                                        if (titulo[i] < '0' || titulo[i] > '9') {
                                            valido = 0;
                                            printf("Erro: O t�tulo de eleitor deve conter apenas n�meros!\n");
                                            break;
                                        }
                                    }
                                } else {
                                    printf("Erro: O t�tulo de eleitor deve ter 12 d�gitos!\n");
                                }
                                
                                if (!valido) {
                                    printf("\t\t\t  T�tulo de eleitor inv�lido. Digite novamente: ");
                                }
                            }

                            printf("\t\t\t  Data de nascimento (dd/mm/aaaa): ");
                            int dia, mes, ano;
                            scanf("%d/%d/%d", &dia, &mes, &ano);
                            temposdeVidaVereador[numCandidatosVereador] = ano * 10000 + mes * 100 + dia;
                            votosVereador[numCandidatosVereador] = 0;
                            numCandidatosVereador++;
                        }
                        printf("Candidato adicionado com sucesso!\n");
                    } else if (opcaoTecnica == 2) {
                        printf("Digite a senha de administrador para iniciar a votacao: ");
                        scanf("%s", senha);
                        if (strcmp(senha, SENHA) == 0) {
                            votacaoAtiva = 1;
                            printf("\t\t\t  Vota��o iniciada com sucesso!\n");
                        } else {
                            printf("\t\t\t  Senha inv�lida.\n");
                        }
                    } else if (opcaoTecnica == 3) {
                        printf("\nResultado da elei��o:\n");
                        for (i = 0; i < numCandidatosPrefeito; i++) {
                            printf("%s - %d votos\n", nomesPrefeito[i], votosPrefeito[i]);
                        }
                        for (i = 0; i < numCandidatosVereador; i++) {
                            printf("%s - %d votos\n", nomesVereador[i], votosVereador[i]);
                        }
                    } else if (opcaoTecnica == 0) {
                        break; // Voltar para o menu normal
                    } else {
                        printf("\t\t\t  Op��o inv�lida.\n");
                    }
                }
            } else {
                printf("\t\t\t Senha incorreta.\n");
            }
        } else if (opcao == 9 && votacaoAtiva) {
            printf("Vota��o encerrada.\n");
            if (strcmp)
            votacaoAtiva = 0;
        } else if (opcao == 2 && votacaoAtiva) {
            printf("\t\t\tDigite o t�tulo de eleitor (12 d�gitos): ");
            scanf("%s", titulo);

            if (tituloUsado) {
                printf("Este t�tulo j� foi usado! \n");
            } else {
                printf("\t\t\tDigite o n�mero do candidato a Prefeito ou Vereador: ");
                scanf("%d", &numero);

                printf("\t\t\tDigite 1 para votar no Prefeito ou 2 para votar no Vereador: ");
                scanf("%d", &tipoVoto);

                if (tipoVoto == 1) { 
                    for (i = 0; i < numCandidatosPrefeito; i++) {
                        if (numerosPrefeito[i] == numero) {
                            votosPrefeito[i]++;
                            encontrou = 1;
                            break;
                        }
                    }
                } else if (tipoVoto == 2) {
                    for (i = 0; i < numCandidatosVereador; i++) {
                        if (numerosVereador[i] == numero) {
                            votosVereador[i]++;
                            encontrou = 1;
                            break;
                        }
                    }
                }
                if (!encontrou) {
                    printf("Candidato n�o encontrado. \n");
                } else {
                    printf("Voto registrado com sucesso! \n");
                    tituloUsado = 1;
                }
            }
        } else {
            printf("\t\t\t Op��o inv�lida. \n");
        }
    }
    return 0;
}

