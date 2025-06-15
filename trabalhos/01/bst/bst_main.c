#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst_funcoes.h"

#define MAX_PALAVRAS 645290

int main(){
    //==========================================================| Inicializar estruturas
    //Criar ponteiro para raiz da BST
    tipo_no *raiz = NULL;
    
    //Criar lista temporaria para armazenar chaves
    //equivalente a: char chaves[645290][TAM_CHAVE], porem, alocado no heap
    char (*tempChaves)[TAM_CHAVE] = calloc(MAX_PALAVRAS, TAM_CHAVE); 
    

    //==========================================================| Abrir arquivos
    //Abrir arquivo ordenado
    FILE* arquivo = fopen("../arquivos/ordenado-words.utf-8.txt", "r");

    //Verificar abertura dos arquivo
    if(arquivo == NULL){
        printf("[ERRO] Nao foi possivel abrir o arquivo\n");
        return -1;
    }

    //==========================================================| Extrair dados e inserir na BST
    //Mover o cursor para a segunda linha
    char linha[50];
    fgets(linha, 50, arquivo);
    
    //Iniciar o cronometro
    clock_t inicio, fim;
    double tempo_insercao_BST;
    inicio = clock();

    //Para todas as linhas ate o fim do arquivo
    int contLinhas = 0;
    //int limitadorDeLeituras = 10;
    while(fgets(linha, 50, arquivo) != NULL /*&& limitadorDeLeituras > 0*/){
        //Decrementar limitador
        //limitadorDeLeituras --;

        //Remover '\n' da linha, deixando apenas a palavra
        int i = 0;
        while(linha[i] != '\0'){
            if(linha[i] == '\n'){
                linha[i] = '\0';
                break;
            }
            i ++;
        }
        
        //Inserir palavra na BST
        raiz = bst_insereIterativo(raiz, linha);

        //Inserir palavra na lista temporaria (sera usada para os experimentos)
        strcpy(tempChaves[contLinhas], linha);
        contLinhas ++;
    }

    //Parar cronometro
    fim = clock();
    //Calcular tempo
    tempo_insercao_BST = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //Fechar arquivo
    fclose(arquivo);

    //==========================================================| Obter informacoes sobre as operacoes
    //BST
    bst_degenerada_mostra(raiz);
    
    //tipo_no* noEncontrado = bst_buscaIterativo(raiz, "zasd");
    //printf("Resultado da busca: %s\n", noEncontrado->chave);
    printf("Altura BST: %d\n", bst_degenerada_altura(raiz));
    printf("Tempo decorrido para insercao BST: %f\n", tempo_insercao_BST);
    printf("Total de linhas lidas: %d\n", contLinhas);

    return 0;
}

