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
    if (raiz == NULL) {
        return novoNo(valor);
    }
    else{
        if (valor > raiz->valor) {
            raiz->direita =  inserir(raiz->direita, valor);
        }
        else{
            raiz->esquerda =  inserir(raiz->esquerda, valor);
        }
        return raiz;
    }
}

// Função de busca
int buscar(No* raiz, int valor) {
    if(raiz == NULL){
        return -1;
    }
    else{
        if(valor == raiz->valor){
            return raiz->valor;
        }
        else{
            if(valor > raiz->valor){
                return buscar(raiz->direita, valor);
            }
            else{
                return buscar(raiz->esquerda, valor);
            }
        }
    }
}

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
    arv = inserir(arv, 25);
    arv = inserir(arv, 10);
    arv = inserir(arv, 30);
    arv = inserir(arv, 5);
    arv = inserir(arv, 12);

    ordem(arv);

    printf("Valor encontrado: %d\n", buscar(arv, 25));
    printf("Valor encontrado: %d\n", buscar(arv, 5));
    printf("Valor encontrado: %d\n", buscar(arv, 13));

    return 0;
}