#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca para tempo
#include <locale.h> // Biblioteca para caracteres especiais

#define totalLinhas 8627367 // 8.6 milhoes
#define tamanhoMaxLinha 10000 // 10 mil

int main()
{
    setlocale(LC_ALL, ""); // Função para caracteres especiais
    int i, j = 0, opcao, contadorVirgulas = 0;
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
    //char palavraBuscada[100];
    //printf("Digite a palavra que deseja buscar: ");
    //scanf("%s", palavraBuscada);
    //printf("Virgulas = %d\n", contadorVirgulas);
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

    for(i=1; i<=50; i++){
        int indice = rand() % totalLinhas; // Gera indíces aleatórios entre 0 e 8.6 milhões
        //printf("\nIndice = %d", indice);
        while(j < indice){
            fgets(linhas[i], tamanhoMaxLinha, arquivo); // Busca indice
            j++;
        }
        fgets(linhas[i], tamanhoMaxLinha, arquivo); // Obtem linha do indice encontrado
        //printf("\nLinha %d: %s", i, linhas[i]);
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
