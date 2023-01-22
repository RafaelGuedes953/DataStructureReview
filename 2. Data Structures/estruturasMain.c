/*
	Name: estruturasMain
	Author: Rafael Guedes
	Date: 22/01/23 13:46
	Description: Codigo principal para teste das estruturas de dados
*/

#include <stdio.h>
#include "menu.h"
#include "fila.h"
#include "pilha.h"

int main(){
    // Teste de fila
    //LFP *f = cria_lfp();
    //menu_fila(f);
    //free(f);

	// Teste de pilha
	LFP *p = cria_lfp();
	menu_pilha(p);
	free(p);
	
    return 0;
}
