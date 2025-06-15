#ifndef __BST_FUNCOES_H__
#define __BST_FUNCOES_H__

#define TAM_CHAVE 50

typedef struct est_no{
   char chave[TAM_CHAVE];
   struct est_no* esq;
   struct est_no* dir; 
} tipo_no;

//Funcoes para insercao, busca e calculo de altura
tipo_no* bst_alocaNo(char chave[]);
tipo_no* bst_insereIterativo(tipo_no *no, char chave[]);
tipo_no* bst_buscaIterativo(tipo_no *no, char chave[]);
int bst_degenerada_altura(tipo_no *no);

//Funcoes para visualizar a arvore
void bst_degenerada_mostra(tipo_no *no);


#endif