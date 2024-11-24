//                                         NOME DA DUPLA: 
//                                         GUILHERME ABTIBOL LIRA VALENTE // MATRICULA: 2402970
//                                         CAUÃ MEDEIROS DE OLIVEIRA      // MATRICULA: 2407822 
//                                         TURMA: ENGS241N01 (ENGENHARIA DE SOFTWARE); TURNO: NOTURNO; 
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 100 
#define SENHA "1234" // Senha para acessar o menu técnico

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
    char titulo[13]; // Variável para armazenar o título de eleitor com 12 dígitos
    int tituloUsado = 0;

    while (1) {
        printf("\t\t\t\t _______________________\n");
        printf("\t\t\t\t|                        |\n");
        printf("\t\t\t\t| **  URNA ELETRONICA ** |\n");
        printf("\t\t\t\t _______________________\n");

        if (!votacaoAtiva) {
            printf("\t\t\t\t ** Olá, Administrador. ** ");
            printf("\t\t\t\t                           \n");
            printf("\t\t\t\t _______________________\n");
            printf("\t\t\t\t                        \n");
            printf("\t\t\t\t  1. Menu Técnico\n");
            printf("\t\t\t\t  0. Sair\n");
            printf("\t\t\t\t _______________________\n");
            printf("\t\t\t\t                           \n");
        } else {
            printf("\t\t\t\t  2. Votar\n"); // Opção de votar só aparece após a votação ser iniciada
            printf("\t\t\t\t  9. Encerrar Votação (Apenas Administrador)\n");
        }

        printf("\t\t\t\t    Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        if (opcao == 1 && !votacaoAtiva) {
            printf("\t\t\t   Digite a senha para o menu técnico: ");
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
                    printf("\t\t\t\t|   2. Iniciar Votação      |\n");
                    printf("\t\t\t\t|   3. Resultado            |\n");
                    printf("\t\t\t\t|   0. Voltar               |\n");
                    printf("\t\t\t\t ___________________________\n");
                    printf("\t\t\t\t|                           |\n");
                    printf("\t\t\t\t    Escolha uma opção: ");
                    scanf("%d", &opcaoTecnica);
                    getchar(); // Limpa o buffer de entrada

                    if (opcaoTecnica == 1) {
                        printf("\t\t\t\t                          \n");
                        printf("\t\t\t  Tipo de candidato:\n");
                        printf("\t\t\t  1. Prefeito\n");
                        printf("\t\t\t  2. Vereador\n");
                        printf("\t\t\t  Escolha a opção: ");
                        scanf("%d", &tipoEleicao);
                        
                        if (tipoEleicao == 1) { // Adicionar Prefeito
                            printf("\t\t\t  Numero do candidato: ");
                            scanf("%d", &numerosPrefeito[numCandidatosPrefeito]);
                            printf("\t\t\t  Nome do candidato: ");
                            scanf("%49s", nomesPrefeito[numCandidatosPrefeito]);
                            

                            printf("\t\t\t  Título de eleitor (12 dígitos): ");
                            int valido = 0;
                            while (!valido) {
                                scanf("%s", titulo);
                                
                                if (strlen(titulo) == 12) {
                                    valido = 1;
                                    for (i = 0; i < 12; i++) {
                                        if (titulo[i] < '0' || titulo[i] > '9') {
                                            valido = 0;
                                            printf("Erro: O título de eleitor deve conter apenas números!\n");
                                            break;
                                        }
                                    }
                                } else {
                                    printf("Erro: O título de eleitor deve ter 12 dígitos!\n");
                                }
                                
                                if (!valido) {
                                    printf("\t\t\t  Título de eleitor inválido. Digite novamente: ");
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
                            

                            printf("\t\t\t  Título de eleitor (12 dígitos): ");
                            int valido = 0;
                            while (!valido) {
                                scanf("%s", titulo);
                                
                                if (strlen(titulo) == 12) {
                                    valido = 1;
                                    for (i = 0; i < 12; i++) {
                                        if (titulo[i] < '0' || titulo[i] > '9') {
                                            valido = 0;
                                            printf("Erro: O título de eleitor deve conter apenas números!\n");
                                            break;
                                        }
                                    }
                                } else {
                                    printf("Erro: O título de eleitor deve ter 12 dígitos!\n");
                                }
                                
                                if (!valido) {
                                    printf("\t\t\t  Título de eleitor inválido. Digite novamente: ");
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
                            printf("\t\t\t  Votação iniciada com sucesso!\n");
                        } else {
                            printf("\t\t\t  Senha inválida.\n");
                        }
                    } else if (opcaoTecnica == 3) {
                        printf("\nResultado da eleição:\n");
                        for (i = 0; i < numCandidatosPrefeito; i++) {
                            printf("%s - %d votos\n", nomesPrefeito[i], votosPrefeito[i]);
                        }
                        for (i = 0; i < numCandidatosVereador; i++) {
                            printf("%s - %d votos\n", nomesVereador[i], votosVereador[i]);
                        }
                    } else if (opcaoTecnica == 0) {
                        break; // Voltar para o menu normal
                    } else {
                        printf("\t\t\t  Opção inválida.\n");
                    }
                }
            } else {
                printf("\t\t\t Senha incorreta.\n");
            }
        } else if (opcao == 9 && votacaoAtiva) {
            printf("Votação encerrada.\n");
            if (strcmp)
            votacaoAtiva = 0;
        } else if (opcao == 2 && votacaoAtiva) {
            printf("\t\t\tDigite o título de eleitor (12 dígitos): ");
            scanf("%s", titulo);

            if (tituloUsado) {
                printf("Este título já foi usado! \n");
            } else {
                printf("\t\t\tDigite o número do candidato a Prefeito ou Vereador: ");
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
                    printf("Candidato não encontrado. \n");
                } else {
                    printf("Voto registrado com sucesso! \n");
                    tituloUsado = 1;
                }
            }
        } else {
            printf("\t\t\t Opção inválida. \n");
        }
    }
    return 0;
}

