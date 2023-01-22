#include <stdio.h>
#include <stdlib.h>
#include "patterns.h"

/*  Definindo as structs*/

typedef struct Item *pont; // define tipo de ponteiro para Item

/*  Struct para o item da fila*/
typedef struct Item{
    int chave; // valor guardado
    pont prox; // ponteiro para o proximo elemento
} Item;

/*  Struct para uma Lista, Fila ou Pilha (LFP)*/
typedef struct LFP{
    pont ini; // aponta para o item inicial da estrutura
    pont fim; // aponta para o item final da estrutura
} LFP;

LFP * cria_lfp(){
    LFP *f = malloc(sizeof(LFP));
    f->fim = NULL;
    f->ini = NULL;
    return f; // retorna endereco para a fila
}

int lfp_vazia(LFP f){
    return (f.ini==NULL);
}

void mostra(LFP f){
    pont aux;
    int  cont=0;
	
	if(lfp_vazia(f)){
		printf("\nErro, estrutura vazia!!!\n\n");
		return;
	}
	
	printf("\nLFP\n");
	
	aux = f.ini;
	while(aux != NULL){
		printf("\t%d; ", aux->chave);
		aux = aux->prox;
        cont++;
	}
	printf("\nTamanho da estrutura: %d\n\n", cont);
}

void insere_inicio(LFP *f, int valor){
    pont novo = (pont) malloc(sizeof(Item));
    novo->chave=valor;
    novo->prox=NULL;

    if (!lfp_vazia(*f)){
        f->fim->prox = novo;
        f->fim = novo;
    }
    else{
        f->ini = novo;
        f->fim = novo;
    }
    
    printf("Valor %d inserido com sucesso!\n",valor);
}
