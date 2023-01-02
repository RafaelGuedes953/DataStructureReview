/* Cabe�alho! 
	Biblioteca criada para 
	definir algoritmos de
	ORDENA��O
	*/

#ifndef _SORT_H
#define _SORT_H

/* Arqwuivo com os c�digos fontes 
	das fun��es especificadas aqui*/
#include "sort.c"

/*  x e y s�o ponteiros para 
	os valores que ser�o trocados*/
void troca_n(int *x, int *y);

/*Para os algoritmos de ordena��o:
	- int *v: ponteiro para o vetor a ser ordenado
	- int n: tamanho do vetor
*/
void bubble_sort(int *v, int n);
void selection_sort(int *v, int n);
void insertion_sort(int *v, int n);
void bucket_sort(int *v, int n);
void count_sort(int *v, int n);


#endif
