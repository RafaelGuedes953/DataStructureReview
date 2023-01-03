/*  Cabecalho! 
	Biblioteca criada para 
	manipulacao de vetores
	*/

#ifndef _VETORES_H
#define _VETORES_H

/*  Arquivo com os codigos fontes 
	das funções especificadas aqui*/
#include "vetores.c"

/*  Funcao utilizada para mostrar vetores na tela
	int  *v: vetor a ser mostrado
	int n: tamanho do vetor
*/
void print_vetor(int *v, int n);

/* Funcao utilizada para criar vetor e preencher com valores aleatorios
	int  *v: vetor a ser criado
	int n: tamanho do vetor
	valores gerados como padrão dentro do range 100
*/
void cria_vetor(int *v, int n);

/* Funcao utilizada para criar vetor e preencher com valores aleatorios
	int  *v: vetor a ser criado
	int n: tamanho do vetor
	int range: valor limite para a geração dos valores do vetor
*/
void cria_vetor_r(int *v, int n, int range);

#endif 

