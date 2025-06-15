#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CHAVE 50
#define MAX_PALAVRAS 645290

//Funcao de comparacao passada como argumento para funcao qsort
int comparaStr(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main(){
    //==========================================================| Inicializar estruturas
    //Criar lista temporaria para armazenar chaves
    char (*chaves)[TAM_CHAVE] = calloc(MAX_PALAVRAS, TAM_CHAVE); 
    //equivalente a: char chaves[645290][TAM_CHAVE], porem, alocado no heap

    //==========================================================| Abrir arquivo
    //Abrir arquivo desordenado
    FILE* arquivo = fopen("./words.utf-8.txt", "r");

    //Criar arquivo ordenado
    FILE* arquivo_ordenado = fopen("./ordenado-words.utf-8.txt", "w");

    //Verificar abertura dos arquivos
    if(arquivo == NULL){
        printf("[ERRO] Nao foi possivel abrir o arquivo original\n");
        return -1;
    }

    if(arquivo_ordenado == NULL){
        printf("[ERRO] Nao foi possivel criar o arquivo ordenado\n");
        return -1;
    }

    //==========================================================| Extrair dados
    //Mover o cursor para a segunda linha
    char linha[50];
    fgets(linha, 50, arquivo);
    
    //Para todas as linhas ate o fim do arquivo
    int cont = 0;
    while(fgets(linha, 50, arquivo) != NULL){
        //Remover '\n' da linha, deixando apenas a palavra
        int i = 0;
        while(linha[i] != '\0'){
            if(linha[i] == '\n'){
                linha[i] = '\0';
                break;
            }
            i ++;
        }
        
        //Inserir na lista temporaria
        strcpy(chaves[cont], linha);
        cont ++;
    }

    //==========================================================| Gerar versao ordenada do arquivo
    //Ordenar lista de chaves
    qsort(chaves, cont, TAM_CHAVE, comparaStr);

    //Escrever no arquivo_ordenado
    for(int i = 0; i < cont; i++){
        fprintf(arquivo_ordenado, "%s\n", chaves[i]);
    }

    //==========================================================| Fechar arquivos
    fclose(arquivo_ordenado);
    fclose(arquivo);


    return 0;
}