#include <stdio.h>
#include <stdlib.h>
#include "patterns.h"
#include "fila.h"


void pop_f(LFP *f){
    if (lfp_vazia(*f)){
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


