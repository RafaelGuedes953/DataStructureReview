#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void pop_p(LFP *p){
    if (lfp_vazia(*p)){
        printf("Erro! A pilha está vazia!");
        return;
    }
    
    if(p->ini==p->fim){ //verifica se ha apenas um elemento
    	// a lista fica vazia
    	printf("\nValor %d removido com sucesso!", p->ini->chave);
		p->ini=NULL;
    	p->fim = NULL;
    	printf("\nA pilha ficou vazia!");
    	return;
	}
    
    pont aux = p->ini;
    pont ant = aux; //define o penultimo elemento
    while(aux->prox!=NULL){
    	ant=aux;
    	aux=aux->prox;
	}
    
	p->fim = ant;
    p->fim->prox = NULL;
    
    printf("\nValor %d removido com sucesso!", aux->chave);
    //printf("\nNovo inicio da pilha: %d",f->ini->chave);

    free(aux); //libera memoria do elemento removido
    mostra(*p);

    return;
}


