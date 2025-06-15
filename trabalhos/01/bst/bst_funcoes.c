#include <stdio.h>
#include <stdlib.h>
#include "bst_funcoes.h"
#include <string.h>

tipo_no* bst_alocaNo(char chave[]){
    tipo_no* novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    strcpy(novoNo->chave, chave);
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

tipo_no* bst_insereIterativo(tipo_no *raiz, char chave[]){
    tipo_no* novoNo = bst_alocaNo(chave);

    tipo_no* y = NULL;
    tipo_no* z = raiz;

    while (z != NULL) {
        y = z;
        if(strcmp(chave, z->chave) > 0){
            z = z->dir;
        } else {
            z = z->esq;
        }
    }

    if(y == NULL){
        return novoNo;
    }
    else if (strcmp(chave, y->chave) > 0) {
        y->dir = novoNo;
    }
    else{
        y->esq = novoNo;
    }
    return raiz;
}


tipo_no* bst_buscaIterativo(tipo_no* raiz, char chave[]) {
    tipo_no* atual = raiz;

    while(atual != NULL){
        if(strcmp(chave, atual->chave) == 0){
            return atual;
        } 
        else if (strcmp(chave, atual->chave) < 0){
            atual = atual->esq;
        } 
        else{
            atual = atual->dir;
        }
    }
    return NULL;
}



int bst_degenerada_altura(tipo_no *no){
    tipo_no* z = no;
    int altura = 0;

    while(z != NULL){
        z = z->dir;
        altura ++;
    }

    return altura;
}

void bst_degenerada_mostra(tipo_no *no){
    tipo_no* z = no;
    
    while(z != NULL){
        printf("[%s]\n", z->chave);
        z = z->dir;
    }
}