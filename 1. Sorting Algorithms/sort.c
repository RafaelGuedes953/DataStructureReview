#include <stdio.h>
#include "vetores.h"
#include "sort.h"

#define tam_bucket 100
#define num_bucket 10

typedef struct bucket{
    int topo;
    int balde[tam_bucket];
}Bucket;

void troca_n(int *x, int *y){
	int aux = *x;
	*x=*y;
	*y=aux;
}

void bubble_sort(int *v, int n){
	int i, j;
	
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(v[j]>v[j+1]){
				troca_n(&v[j],&v[j+1]);
				//print_vetor(v,n);
			}
				
	print_vetor(v,n);
}

void selection_sort(int *v, int n){
	int i, j,min_i;
	
	for(i=0;i<n-1;i++){
		min_i=i;
		for(j=i+1;j<n;j++)
			if(v[min_i]>v[j])
				min_i=j;
		if(min_i!=i)
			troca_n(&v[i],&v[min_i]);
	}
	
	print_vetor(v,n);
}

void insertion_sort(int *v, int n){
	int i, j, key;
	
	for(i=1;i<n;i++){
		j=i-1;
		key = v[i];
		while(j>=0 && v[j]>key){
			v[j+1]=v[j];
			j--;
			//print_vetor(v,n);
		}
		v[j+1]=key;
	}
	print_vetor(v,n);
}

// utilizado para valores uniformemente distribuídos
void bucket_sort(int *v, int n){
	int i,j;
	Bucket b[num_bucket];
	
	//inicializa todos os "topo"
	for(i=0;i<num_bucket;i++) 
		b[i].topo=0;
     
	//verifica em que balde o elemento deve ficar
	for(i=0;i<n;i++){
		j=(num_bucket)-1;
		while(j>=0){
			if(v[i]>=j*10){
				b[j].balde[b[j].topo]=v[i];
				(b[j].topo)++;
				break;
			}
			j--;
		}
	}
	
	/*printf("--------ini_teste--------");
	// verificar divisão dos baldes
	for(i=0;i<num_bucket;i++){
		print_vetor(b[i].balde,b[i].topo);
		printf("\n");
	}
	printf("--------fim_teste--------");*/
    
    //ordena os baldes
	for(i=0;i<num_bucket;i++)
		if(b[i].topo)
			bubble_sort(b[i].balde,b[i].topo);
		
	//põe os elementos dos baldes de volta no vetor
	for(j=0;j<num_bucket;j++)
		for(i=0;i<b[j].topo;i++)
			v[i]=b[j].balde[i];
}

void count_sort(int *v, int n){
	int output[10], i;

	// Encontrar o maior elemento do vetor
	int max = v[0];
	for (i = 1; i < n;i++)
		if (v[i] > max)
			max = v[i];

  	// O tamanho de count deve ser pelo menos (max+1)
	int count[10]; // Ficaria melhor usando alocação dinâmica

	// Inicializa o vetor count com zeros
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	// Armazena a contagem de cada elemento
	for (i = 0; i < n; i++)
		count[v[i]]++;

	// Faz o cálculo cumulativo de cada elemento
	for (i = 1; i <= max; i++)
		count[i] += count[i-1];

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (i = n - 1; i >= 0; i--) {
		output[count[v[i]] - 1] = v[i];
		count[v[i]]--;
	}

	// Copy the sorted elements into original array
	for (i = 0; i < n; i++)
		v[i] = output[i];
	
	print_vetor(v,n);
}

