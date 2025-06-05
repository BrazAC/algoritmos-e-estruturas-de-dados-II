#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int valor;
    struct no* esquerda;
    struct no* direita;
} No;

No* novoNo(int valor) {
    No* raiz = (No*)malloc(sizeof(No));
    raiz->valor = valor;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    return raiz;
}

// Função de inserção
No* inserir(No* raiz, int valor) {
    if(raiz == NULL){
        return novoNo(valor);
    }
    else{
        if(valor > raiz->valor){
            raiz->direita = inserir(raiz->direita, valor);
        }
        else{
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        return raiz;
    }
}

// retorna 1 se cheia, 0 se não
int arvore_cheia(No* raiz){
    if(raiz == NULL){
        return 1;
    }
    if(raiz->esquerda == NULL && raiz->direita == NULL){
        return 1; 
    }
    else if (raiz->esquerda != NULL && raiz->direita != NULL){
        int esq =  arvore_cheia(raiz->esquerda);
        int dir =  arvore_cheia(raiz->direita);

        if (esq == 1 && dir == 1) {
            return 1;
        }else{
            return 0;
        }
    }
    else {
        return 0;
    }
};

void ordem(No* raiz){
    if (raiz == NULL) {
        return;
    }
    else{
        ordem(raiz->esquerda);
        printf("[%d]\n", raiz->valor);
        ordem(raiz->direita);
    }
}

int main(){
    No* arv = NULL;
    arv = inserir(arv, 10);
    arv = inserir(arv, 5);
    

    ordem(arv);

    if(arvore_cheia(arv)){
        printf("E cheia\n");
    }else{
        printf("Nao e cheia\n");
    }

    return 0;
}