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

LISTA* insere_ordenado(LISTA* li, int i){
    if (li == NULL) {
        li = cria_no(i);
    }
    else{
        //Posicionar ponteiros auxiliares
        LISTA *aux = li;
        LISTA *aut = NULL;
        while (aux != NULL){
            //Dado i > dadoAtual?
            if (i > aux->info){
                //Avancar prox noh
                aut = aux;
                aux = aux->prox;
            }else{
                break;
            }
        }
        
        //Alocar noh
        LISTA* novoNoh = cria_no(i);

        //Se for o primeiro elemento
        if (aut == NULL){
            novoNoh->prox = aux;
            li = novoNoh;
        }
        //Se for o ultimo elemento
        else if (aux == NULL){
            aut->prox = novoNoh;
        }
        //Se for um do "meio"
        else{
            aut->prox = novoNoh;
            novoNoh->prox = aux;
        }
    }   
    return li;
}

int main(){
    LISTA* mLista = NULL;
    mLista = insere_ordenado(mLista, 3);
    mLista = insere_ordenado(mLista, 5);
    mLista = insere_ordenado(mLista, 4);
    mLista = insere_ordenado(mLista, 11);
    mLista = insere_ordenado(mLista, 10);
    mLista = insere_ordenado(mLista, 9);
    mLista = insere_ordenado(mLista, 0);
    mLista = insere_ordenado(mLista, 7);
    
    LISTA *aux = mLista;
    while (aux != NULL){
        printf("[%d]", aux->info);
        aux = aux->prox;
    }
    printf("\n");

    return 0;
}