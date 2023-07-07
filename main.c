#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca para tempo
#include <locale.h> // Biblioteca para caracteres especiais
#include <string.h>

#define totalLinhas 8627000 // 8.6 milhoes
#define tamanhoMaxLinha 10000 // 10 mil

void lerAlunos(FILE *arquivo, char linhas[][tamanhoMaxLinha]);

void visualizarAluno(int numAluno, char *token);

int main()
{
    setlocale(LC_ALL, ""); // Função para caracteres especiais
    int opcao, numAluno, i;
    srand(time(NULL)); // Semente para números aleatórios
    char linhas[51][tamanhoMaxLinha]; // Vetor para armazenar 50 linhas aleatórias + cabeçalho

    FILE *arquivo = fopen("microdados_enem_2016_coma.csv", "r"); // Abre arquivo csv em modo leitura

    do{
       printf("\n\n--> Análise Enem 2016 <--\n");
       printf("\nComandos de execução: \n0. Sair \n1. Ler 50 alunos aleatórios \n2. Visualizar colunas\n3. Visualizar aluno específico.\n");
       printf("\nComandos de funcionamento: \n4. Visualizar todas colunas \n5. Visualizar todos alunos \n6. Visualizar tudo aluno específico.\n\n");
       scanf("%d", &opcao);
       switch(opcao){
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            lerAlunos(arquivo, linhas);
            printf("\n50 alunos aleatórios lidos com sucesso!");
            break;
        case 2:
            printf("\nNU_INSCRICAO, NO_MUNICIPIO_RESIDENCIA, SG_UF_RESIDENCIA, NU_IDADE, NU_NOTA_CN, NU_NOTA_CH, NU_NOTA_LC, NU_NOTA_MT, NU_NOTA_REDACAO, Q001, Q002, Q006, Q025");
            break;
        case 3:
            // Separa as colunas do aluno
            printf("\nQue aluno deseja visualizar? ");
            int numAluno;
            if (scanf("%d", &numAluno) != 1) {
                printf("Entrada inválida. Digite um número válido.\n");
                break;
            }
            if (numAluno == 0)
                break;

            char *token = strtok(linhas[numAluno], ",");

            visualizarAluno(numAluno, token);

            break;

        case 4:
            fseek(arquivo, 0, SEEK_SET);
            fgets(linhas[0], tamanhoMaxLinha, arquivo); // Lê e imprime cabeçalho (linha 0 do arquivo)
            printf("\n%s", linhas[0]);
            break;

        case 5:
            for(i=1; i<51; i++)
                printf("\nAluno %d: %s", i, linhas[i]);
            break;

        case 6:
            printf("\nQue aluno deseja visualizar? ");
            scanf("%d", &numAluno);
            if(numAluno==0)
                break;
            else
                printf("\nAluno %d: %s", numAluno, linhas[numAluno]);
            break;

        default:
            printf("\nOpção inválida!");
            break;
        }
    }while(opcao!=0);


    fclose(arquivo); // Fecha o arquivo

    return 0;
}

void lerAlunos(FILE *arquivo, char linhas[][tamanhoMaxLinha]){
    int i, j = 0;
    // Confirmações se arquivo foi carregado com sucesso:
    if(arquivo != NULL){
        //printf("Arquivo lido com sucesso!\n");
    }
    else{
        printf("Erro ao carregar o arquivo!\n");
        return 1;
    }

    for(i=1; i<=50; i++){
        int indice = rand() % totalLinhas; // Gera indíces aleatórios entre 0 e 8.6 milhões
        //printf("\n\nIndice = %d", indice);
        while(j < indice){
            fgets(linhas[i], tamanhoMaxLinha, arquivo); // Busca indice
            j++;
        }
        fgets(linhas[i], tamanhoMaxLinha, arquivo); // Obtem linha do indice encontrado
        //printf("\nEstudante %d: ", i);
        //printf("\nEstudante %d: %s", i, linhas[i]);
    }
}

void visualizarAluno(int numAluno, char *token){
    int coluna = 1;
    printf("\nAluno %d", numAluno);
    while (token != NULL) {
        switch (coluna) {
            case 1:
                printf("\nInscrição: %s\n", token);
                break;
            case 4:
                printf("Cidade: %s\n", token);
                break;
            case 6:
                printf("Estado: %s\n", token);
                break;
            case 7:
                printf("Idade: %s\n", token);
                break;
            case 85:
                printf("Nota Ciências da Natureza: %s\n", token);
                break;
            case 86:
                printf("Nota Ciências Humanas: %s\n", token);
                break;
            case 87:
                printf("Nota Linguagens e Códigos: %s\n", token);
                break;
            case 88:
                printf("Nota Matemática: %s\n", token);
                break;
            case 104:
                printf("Nota Redação: %s\n", token);
                break;
            case 105:
                printf("Escolaridade do pai: ");
                if(strcmp(token, "A") == 0)
                    printf("Nunca estudou.\n");
                else if(strcmp(token, "B") == 0)
                    printf("Não completou a 4ª série/5º ano do Ensino Fundamental.\n");
                else if(strcmp(token, "C") == 0)
                    printf("Completou a 4ª série/5º ano, mas não completou a 8ª série/9º ano do Ensino Fundamental.\n");
                else if(strcmp(token, "D") == 0)
                    printf("Completou a 8ª série/9º ano do Ensino Fundamental, mas não completou o Ensino Médio.\n");
                else if(strcmp(token, "E") == 0)
                    printf("Completou o Ensino Médio, mas não completou a Faculdade.\n");
                else if(strcmp(token, "F") == 0)
                    printf("Completou a Faculdade, mas não completou a Pós-graduação.\n");
                else if(strcmp(token, "G") == 0)
                    printf("Completou a Pós-graduação.\n");
                else if(strcmp(token, "H") == 0)
                    printf("Não sei.\n");
                break;
            case 106:
                printf("Escolaridade da mãe: ");
                if(strcmp(token, "A") == 0)
                    printf("Nunca estudou.\n");
                else if(strcmp(token, "B") == 0)
                    printf("Não completou a 4ª série/5º ano do Ensino Fundamental.\n");
                else if(strcmp(token, "C") == 0)
                    printf("Completou a 4ª série/5º ano, mas não completou a 8ª série/9º ano do Ensino Fundamental.\n");
                else if(strcmp(token, "D") == 0)
                    printf("Completou a 8ª série/9º ano do Ensino Fundamental, mas não completou o Ensino Médio.\n");
                else if(strcmp(token, "E") == 0)
                    printf("Completou o Ensino Médio, mas não completou a Faculdade.\n");
                else if(strcmp(token, "F") == 0)
                    printf("Completou a Faculdade, mas não completou a Pós-graduação.\n");
                else if(strcmp(token, "G") == 0)
                    printf("Completou a Pós-graduação.\n");
                else if(strcmp(token, "H") == 0)
                    printf("Não sei.\n");
                break;
            case 110:
                printf("Renda mensal da família: ");
                if(strcmp(token, "A") == 0)
                    printf("Nenhuma renda.\n");
                else if(strcmp(token, "B") == 0)
                    printf("Até R$ 788,00.\n");
                else if(strcmp(token, "C") == 0)
                    printf("De R$ 788,01 até R$ 1.182,00.\n");
                else if(strcmp(token, "D") == 0)
                    printf("De R$ 1.182,01 até R$ 1.572,00.\n");
                else if(strcmp(token, "E") == 0)
                    printf("De R$ 1.572,01 até R$ 1.970,00.\n");
                else if(strcmp(token, "F") == 0)
                    printf("De R$ 1.970,01 até R$ 2.364,00.\n");
                else if(strcmp(token, "G") == 0)
                    printf("De R$ 2.364,01 até R$ 3.152,00.\n");
                else if(strcmp(token, "H") == 0)
                    printf("De R$ 3.152,01 até R$ 3.940,00.\n");
                else if(strcmp(token, "I") == 0)
                    printf("De R$ 3.940,01 até R$ 4.728,00.\n");
                else if(strcmp(token, "J") == 0)
                    printf("De R$ 4.728,01 até R$ 5.516,00.\n");
                else if(strcmp(token, "K") == 0)
                    printf("De R$ 5.516,01 até R$ 6.304,00.\n");
                else if(strcmp(token, "L") == 0)
                    printf("De R$ 6.304,01 até R$ 7.092,00.\n");
                else if(strcmp(token, "M") == 0)
                    printf("De R$ 7.092,01 até R$ 7.880,00.\n");
                else if(strcmp(token, "N") == 0)
                    printf("De R$ 7.880,01 até R$ 9.456,00.\n");
                else if(strcmp(token, "O") == 0)
                    printf("De R$ 9.456,01 até R$ 11.820,00.\n");
                else if(strcmp(token, "P") == 0)
                    printf("De R$ 11.820,01 até R$ 15.760,00.\n");
                else if(strcmp(token, "Q") == 0)
                    printf("Mais de 15.760,00.\n");
                break;
            case 129:
                printf("Acesso à internet na residência: ");
                if(strcmp(token, "A") == 0)
                    printf("Não.\n");
                else if(strcmp(token, "B") == 0)
                    printf("Sim.\n");
                break;
            default:
                //printf("Coluna %d: %s\n", coluna, token);
                break;
        }
        token = strtok(NULL, ",");
        coluna++;
    }
}
