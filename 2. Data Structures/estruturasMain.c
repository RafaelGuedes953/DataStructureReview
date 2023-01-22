/*
	Name: estruturasMain
	Author: Rafael Guedes
	Date: 22/01/23 13:46
	Description: Codigo principal para teste das estruturas de dados
*/

#include <stdio.h>
#include "menu.h"
#include "fila.h"

int main(){
    
    Fila *f = cria_fila();

    menu_fila(f);
    return 0;
}
