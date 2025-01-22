// HEMOBANCO V2

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define MAX_DOADORES 100
#define MAX_NOME     50

struct doador
{
    char nome[MAX_NOME + 1];
    int idade;
    float peso;
    bool estaNutrido;
    bool estaResfriado;
};

typedef struct doador doador;

void toLower(char * opcao)
{
    for(int i = 0; opcao[i] != '\0'; i++)
    {
        if(opcao[i] >= 'A' && opcao[i] <= 'Z')
        {
            opcao[i] += ('a' - 'A');
        }
    }
}

bool pegaResposta()
{
    char opcao[4];
    while(1)
    {
        scanf(" %3[^\n]s", opcao);
        toLower(opcao);
        if(strcmp(opcao, "sim") == 0)
            return true;
        if(strcmp(opcao, "nao") == 0)
            return false;
        printf("As opcoes sao 'sim' ou 'nao'...\n");
    }
}

doador pegaDoador()
{
    doador x;
    
    printf("Nome completo (max %i caracteres): ", MAX_NOME);
    scanf(" %100[^\n]s", x.nome);

    printf("Idade: ");
    scanf("%i", &(x.idade));
    
    printf("Peso: ");
    scanf("%f", &(x.peso));

    printf("Esta bem alimentado? (sim/nao) ");
    x.estaNutrido = pegaResposta();
    
    printf("Esta resfriado? (sim/nao) ");
    x.estaResfriado = pegaResposta();
    
    return x;
}

bool estaApto(doador x)
{
    return x.idade >= 16
        && x.idade <= 69
        && x.peso >= 50
        && x.estaNutrido
        && !x.estaResfriado;
}

void gerarRelatorio(doador doadores[], int numDoadores, int opcao)
{
    for(int i = 0; i < numDoadores; i++)
    {
        if(estaApto(doadores[i]))
        {
            if(opcao == 1 || opcao == 2)
                printf("doador %i - %s: esta apto!\n", i + 1, doadores[i].nome);
        }
        else
        {
            if(opcao == 1 || opcao == 3)
                printf("doador %i - %s: nao esta apto!\n", i + 1, doadores[i].nome);
        }
    }
}

int main()
{
    doador doadores[MAX_DOADORES];
    int numDoadores = 0;
    int continuar = true;

    while(continuar)
    {
        system(CLEAR);

        printf("Bem vindo ao Hemobanco!\n");
        printf("1 - Cadastrar doador\n");
        printf("2 - Gerar relatorio\n");
        printf("0 - Sair\n");
        
        int opcao;
        scanf("%i", &opcao);

        switch(opcao)
        {
            case 0:
                continuar = false;
                break;

            case 1:
                if(numDoadores >= MAX_DOADORES)
                {
                    printf("Limite de doadores excedido!\n");
                }
                else
                {
                    doadores[numDoadores] = pegaDoador();
                    numDoadores++;
                    printf("Doador cadastrado!\n");
                }
                break;
            
            case 2:
                if(numDoadores <= 0)
                {
                    printf("Nao ha doadores cadastrados...\n");
                }
                else
                {
                    system(CLEAR);
                    printf("Escola o relatorio:\n");
                    printf("1 - Relatorio completo\n");
                    printf("2 - Apenas doadores aptos\n");
                    printf("3 - Apenas doadores nao aptos\n");
                    printf("0 - Voltar\n");

                    opcao = 4;
                    while(opcao >= 4)
                    {
                        scanf("%i", &opcao);
                        switch(opcao)
                        {
                            case 0:
                                break;
                            
                            case 1:
                                printf("Relacao de doadores:\n");
                                gerarRelatorio(doadores, numDoadores, opcao);
                                break;
                            
                            case 2:
                                printf("Relacao de doadores aptos:\n");
                                gerarRelatorio(doadores, numDoadores, opcao);
                                break;
                            
                            case 3:
                                printf("Relacao de doadores nao aptos:\n");
                                gerarRelatorio(doadores, numDoadores, opcao);
                                break;
                            
                            default:
                                printf("Opcao invalida!\n");
                                break;
                        }
                    }
                }
                break;

            default:
                printf("Opcao invalida...");
                break;
        }

        if(opcao != 0)
        {
            printf("Pressione ENTER para continuar...\n");
            fflush(stdin);
            char tecla;
            scanf("%c", &tecla);
            fflush(stdin);
        }
    }
    
    return 0;
}
