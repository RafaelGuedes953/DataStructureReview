/*  Cabecalho! 
	Biblioteca criada para definir 
	algoritmos de ordenacao
	*/

#ifndef _SORT_H
#define _SORT_H

/*  Arquivo com os codigos fontes 
	das funcoes especificadas aqui*/
#include "sort.c"

/*  x e y sao ponteiros para 
	os valores que serao trocados*/
void troca_n(int *x, int *y);

/*  Para os algoritmos de ordenacao:
	- int *v: ponteiro para o vetor a ser ordenado
	- int n: tamanho do vetor*/

void bubble_sort(int *v, int n);
void selection_sort(int *v, int n);
void insertion_sort(int *v, int n);
void bucket_sort(int *v, int n);
void count_sort(int *v, int n);

#endif
