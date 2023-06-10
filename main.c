#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca para tempo
#include <locale.h> // Biblioteca para caracteres especiais
#include <string.h>

#define totalLinhas 8627367 // 8.6 milhoes
#define tamanhoMaxLinha 10000 // 10 mil

/*
typedef struct dados{
    int NU_INSCRICAO;
    int NU_NOTA_COMP1;
};*/

int main()
{
    setlocale(LC_ALL, ""); // Função para caracteres especiais
    int i, j = 0, opcao, contadorColunas = 0;
    char linhas[51][tamanhoMaxLinha]; // Vetor para armazenar 50 linhas aleatórias + cabeçalho
    srand(time(NULL)); // Semente para números aleatórios

    FILE *arquivo = fopen("microdados_enem_2016_coma.csv", "r"); // Abre arquivo csv em modo leitura
    // Confirmações se arquivo foi carregado com sucesso:
    if(arquivo != NULL){
        printf("Arquivo lido com sucesso!\n");
    }
    else{
        printf("Erro ao carregar o arquivo!\n");
        return 1;
    }

    // Lê e imprime cabeçalho (linha 0 do arquivo)
    fgets(linhas[0], tamanhoMaxLinha, arquivo);
    printf("\nLinha 0: %s", linhas[0]);

    // ----------------- EM CONSTRUÇÂO -----------------
    // Colunas --> Estudante = 0; Nota:
    // NU_NOTA_COMP1,NU_NOTA_COMP2,NU_NOTA_COMP3,NU_NOTA_COMP4,NU_NOTA_COMP5,NU_NOTA_REDACAO
    /*
    int contadorLinhas = 0;
    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            contadorLinhas++;
        }
    }
    printf("\nLinhas = %d", contadorLinhas);
    */
  // ----------------- ------------- -----------------

    //char *token = strtok(linhas, ",");

    //while (token != NULL) {
        //printf("%s\n", token);
        //token = strtok(NULL, ",");
    //}

    for(i=1; i<=50; i++){
        int indice = rand() % totalLinhas; // Gera indíces aleatórios entre 0 e 8.6 milhões
        printf("\n\nIndice = %d", indice);
        while(j < indice){
            fgets(linhas[i], tamanhoMaxLinha, arquivo); // Busca indice
            j++;
        }
        fgets(linhas[i], tamanhoMaxLinha, arquivo); // Obtem linha do indice encontrado
        //printf("\nEstudante %d: ", i);
        printf("\nEstudante %d: %s", i, linhas[i]);

        char *dadosColunas = strtok(linhas[i], ","); // retorna um ponteiro para a primeira virgula (delimitador) encontrado na string)
        int contadorColunas = 0;

        while (dadosColunas != NULL) { // Percorre a linha

            switch(contadorColunas){
                case 107: // Caso esteja na coluna 107 (NU_NOTA_COMP1)
                    printf("\n> NU_NOTA_COMP1 = %s", dadosColunas); // Imprime dado dessa coluna
                    break;
                case 108:
                    printf("\n> NU_NOTA_COMP2 = %s", dadosColunas);
                    break;
                case 109:
                    printf("\n> NU_NOTA_COMP3 = %s", dadosColunas);
                    break;
                case 110:
                    printf("\n> NU_NOTA_COMP4 = %s", dadosColunas);
                    break;
                case 111:
                    printf("\n> NU_NOTA_COMP5 = %s", dadosColunas);
                    break;
                case 112:
                    printf("\n> NU_NOTA_REDACAO = %s", dadosColunas);
                    break;
            }

            dadosColunas = strtok(NULL, ","); // obtém o próximo dado da string, avançando para o próximo delimitador (retorna NULL caso não encontre)
            contadorColunas++; // incrementa contador de colunas
        }

        //
        /*
        while (fgets(linhas[indice], tamanhoMaxLinha, arquivo) != NULL) {
        char *token = strtok(linhas, ",");
        int contadorColunas = 0;

        // Percorre os tokens da linha
        while (token != NULL) {
            if (contadorColunas == 107) { // virgulas = 107 até encontrar a primeira nota
                printf("Dado da coluna %d: %s\n", 107, token);
                break;
            }
            token = strtok(NULL, ",");
            contadorColunas++;
            }
        }*/
    }

    // ----------------- EM CONSTRUÇÂO -----------------
    /*do{
        printf("\n--> Análise de dados ENEM 2016 <--");
        printf("\n Linhas = 8627367   Colunas = 166");
        printf("\n\nQue coluna deseja visualizar? ");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                printf("\nSaindo...");
                break;
            default:
                printf("\nOpcao invalida!");
        }
    } while(opcao!=0);*/
    // ----------------- ------------- -----------------

    fclose(arquivo); // Fecha o arquivo

    return 0;
}
