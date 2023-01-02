#include <stdio.h>
#include <stdlib.h>

void troca_n(int *x, int *y){
	//printf("\na: %d b: %d",*x,*y);
	int aux = *x;
	*x=*y;
	*y=aux;
	//printf("\na: %d b: %d",*x,*y);
}

int main(){
	int a=3, b=6;
	printf("a: %d b: %d",a,b);
	
	troca_n(&a,&b);
	
	printf("\nx: %d y: %d",a,b);


	return 0;
}

