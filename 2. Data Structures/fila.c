#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct Item *pont; // define tipo de ponteiro para Item

/*  Struct para o item da fila*/
typedef struct Item{
    int chave; // valor guardado
    pont prox; // ponteiro para o proximo elemento
} Item;

/*  Struct para a propria fila*/
typedef struct Fila{
    pont ini; // aponta para o item inicial da fila
    pont fim; // aponta para o item final da fila
} Fila;

Fila * cria_fila(){
    Fila *f = malloc(sizeof(Fila));
    f->fim = NULL;
    f->ini = NULL;
    return f; // retorna endereco para a fila
}

int fila_vazia(Fila f){
    return (f.ini==NULL);
}

void mostra(Fila f){
    pont aux;
    int  cont=0;
	
	if(fila_vazia(f)){
		printf("\nErro, Lista vazia!!!\n\n");
		return;
	}
	
	printf("\nFila\n");
	
	aux = f.ini;
	while(aux != NULL){
		printf("\t%d; ", aux->chave);
		aux = aux->prox;
        cont++;
	}
	printf("\nTamanho da lista: %d\n\n", cont);
}

void insere(Fila *f, int valor){
    pont novo = (pont) malloc(sizeof(Item));
    novo->chave=valor;
    novo->prox=NULL;

    if (!fila_vazia(*f)){
        f->fim->prox = novo;
        f->fim = novo;
    }
    else{
        f->ini = novo;
        f->fim = novo;
    }
    
    printf("Valor %d inserido com sucesso!\n",valor);
}

void pop(Fila *f){
    if (fila_vazia(*f)){
        printf("Erro! A fila está vazia!");
        return;
    }
    
    pont aux = f->ini;
    f->ini = f->ini->prox;

    printf("\nValor %d removido com sucesso!", aux->chave);
    //printf("\nNovo inicio da fila: %d",f->ini->chave);

    free(aux); //libera memoria da celula removida

    return;
}


