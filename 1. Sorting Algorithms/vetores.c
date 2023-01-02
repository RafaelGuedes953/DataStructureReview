#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

void print_vetor(int *v, int n){
	int i;
	for (i=0;i<n;i++)
		printf("%d ",v[i]);
	printf("\n");
}

void cria_vetor(int *v, int n){
	int i;
	//srand(time(NULL));
	
	for (i=0;i<n;i++)
		v[i] = 100+rand()%100;
	print_vetor(v,n);
}

void cria_vetor_r(int *v, int n, int range){
	int i;
	
	for (i=0;i<n;i++)
		v[i] = rand()%range;
	print_vetor(v,n);
}

