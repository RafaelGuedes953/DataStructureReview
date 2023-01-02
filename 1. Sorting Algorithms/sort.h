/* Cabeçalho! 
	Biblioteca criada para 
	definir algoritmos de
	ORDENAÇÃO
	*/

#ifndef _SORT_H
#define _SORT_H

/* Arqwuivo com os códigos fontes 
	das funções especificadas aqui*/
#include "sort.c"

/*  x e y são ponteiros para 
	os valores que serão trocados*/
void troca_n(int *x, int *y);

/*Para os algoritmos de ordenação:
	- int *v: ponteiro para o vetor a ser ordenado
	- int n: tamanho do vetor
*/
void bubble_sort(int *v, int n);
void selection_sort(int *v, int n);
void insertion_sort(int *v, int n);
void bucket_sort(int *v, int n);
void count_sort(int *v, int n);


#endif
