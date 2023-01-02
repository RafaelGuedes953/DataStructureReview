/*
	Name: ordenacaoMain
	Author: Rafael Guedes
	Date: 02/01/23 17:16
	Description: Código principal para teste dos algoritmos de ordenação
*/

#include <stdio.h>
#include "vetores.h"
#include "sort.h"

#define TAM 6

int main(){
	int v[TAM];
	cria_vetor(v,TAM);
	//cria_vetor_r(v,TAM,10);
	//bubble_sort(v,TAM);
	selection_sort(v,TAM);
	//insertion_sort(v,TAM);
	//bucket_sort(v,TAM);
	//count_sort(v,TAM);
	
	return 0;
}

