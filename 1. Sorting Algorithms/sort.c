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

// utilizado para valores uniformemente distribuidos
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
	// verificar divisao dos baldes
	for(i=0;i<num_bucket;i++){
		print_vetor(b[i].balde,b[i].topo);
		printf("\n");
	}
	printf("--------fim_teste--------");*/
    
    //ordena os baldes
	for(i=0;i<num_bucket;i++)
		if(b[i].topo)
			bubble_sort(b[i].balde,b[i].topo);
		
	//insere os elementos dos baldes de volta no vetor
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
	int count[10]; // Ficaria melhor usando alocacao dinamica

	// Inicializa o vetor count com zeros
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	// Armazena a contagem de cada elemento
	for (i = 0; i < n; i++)
		count[v[i]]++;

	// Faz o c�lculo cumulativo de cada elemento
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

/* Algoritmos para MergeSort*/
void merge(int *v, int esq, int meio, int dir){
    int i, j, k; // contadoras
	int t_esq = meio - esq + 1; // tamanho do sub-array esquerdo
	int t_dir =  dir - meio; // tamanho do sub-array direito
	int L[t_esq], R[t_dir]; // arrays temporários

	/* Copiar dados para os arrays temporários L[] e R[] */
	for(i = 0; i < t_esq; i++)
		L[i] = v[esq+i];

	for(j = 0; j < t_dir; j++)
		R[j] = v[meio+1+j];

	// Mesclar os arrays temporários de volta no v[esq..dir]
	i = 0; // índice inicial do sub-array esquerdo
	j = 0; // índice inicial do sub-array direito
	k = esq; // índice inicial do array mesclado

	while (i < t_esq && j < t_dir){
		if (L[i] <= R[j]){
			v[k] = L[i];
			i++;
		}
		else{
			v[k] = R[j];
			j++;
		}
		k++;
	}

	/* Apenas um dos whiles abaixo roda para unir 
		os valores restantes, seja de L ou de R*/
	
	while (i < t_esq){ // Copiar os elementos restantes de L[]
		v[k] = L[i];
		i++;
		k++;
	}
	
	while (j < t_dir){ // Copiar os elementos restantes de R[]
		v[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int *v, int esq, int dir){
	int meio;
	//printf("recursao esq=%d dir=%d\n",esq,dir);
	if (esq >= dir) 
		return;
    meio = (esq+dir)/2;
	//printf("valores dividindo\n");
	//print_vetor(v,dir+1);
    merge_sort(v, esq, meio);
    merge_sort(v, meio+1, dir);
    merge(v, esq, meio, dir);
	//printf("valores arrumando\n");
	//print_vetor(v,dir+1);
}

/* Algoritmos para QuickSort*/
int separa(int *v, int ini, int fim){
	int pivot = v[fim];
	int i = (ini - 1);

	for (int j = ini; j <= fim- 1; j++) {
		if (v[j] <= pivot){
			i++;
			troca_n(&v[i], &v[j]);
		}
	}
	troca_n(&v[i + 1], &v[fim]); 
	return (i + 1); 
}

void quick_sort(int *v, int ini, int fim){
	if (ini < fim){
		int pi = separa(v, ini, fim);
		quick_sort(v, ini, pi - 1);
		quick_sort(v, pi + 1, fim);
	}
	print_vetor(v,fim+1);
}
