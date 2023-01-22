/*  Cabecalho! 
	Biblioteca criada para definir 
	operacoes da estrutura FILA
	*/

#ifndef _FILA_H
#define _FILA_H

/*  Arquivo com os codigos fontes 
	das funcoes especificadas aqui*/
#include "fila.c"

// Cria uma fila vazia
Fila * cria_fila();

/*  Função que insere um valor no fim da fila*/
void insere(Fila *f, int valor);

/*  Função que remove um valor no inicio da fila*/
void pop(Fila *f);

/*  Função que mostra os valores da fila*/
void mostra(Fila f);


#endif
