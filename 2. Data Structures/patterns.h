/*  Cabecalho! 
	Biblioteca criada para definir as estruturas e 
	funcoes padrao comuns entre Fila, Pilha e Lista
	*/

#ifndef _PATTERNS_H
#define _PATTERNS_H

/*  Arquivo com os codigos fontes 
	das funcoes especificadas aqui*/
#include "patterns.c"

/* Definindo prototipos das funcoes*/

// Cria uma lfp vazia
LFP * cria_lfp();

// Verifica se a lfp está vazia
int lfp_vazia(LFP f);

//  Função que insere um valor no fim da estrutura
void insere_inicio(LFP *f, int valor);

//  Função que mostra os valores da estrutura
void mostra(LFP f);

#endif
