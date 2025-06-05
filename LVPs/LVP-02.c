#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista* prox;
}LISTA;

LISTA* cria_no(int v){
	LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
	novo->info = v;
	novo->prox = NULL;
	return novo;
}

LISTA* insere_fim(LISTA* li, int i){
    if(li == NULL){
        li = cria_no(i);
        return li;
    }
    else{
        LISTA *aux = li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = cria_no(i);
        return li;
    }
}

int main(){
    LISTA *mLista = NULL;

    mLista = insere_fim(mLista, 3);
    mLista = insere_fim(mLista, 8);
    mLista = insere_fim(mLista, 5);

    LISTA *aux = mLista;
    while(aux != NULL){
        printf("[%d]", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
