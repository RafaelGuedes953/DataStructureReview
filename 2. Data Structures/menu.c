#include <stdio.h>
#include "menu.h"
#include "fila.h"

void menu_fila(Fila *f){
    int op, n;

    printf("\n***** Menu *****");
    
    //printf("1 - Criar fila;"); \\ Tem que ser feito no programa main
    printf("\n1 - Inserir elemento;");
    printf("\n2 - Remover elemento;");
    printf("\n3 - Mostrar fila;");
    printf("\n0 - Encerrar");
    
    printf("\n\tSelcione a opcao desejada: ");
    scanf("%d",&op);

    switch(op){
        case 1:
            printf("\nDigite um valor para a fila: ");
            scanf("%d",&n);
            insere(f,n);
            mostra(*f);
            menu_fila(f);
            break;
        
        case 2:
            pop(f);
            menu_fila(f);
            break;

        case 3:
            mostra(*f);
            menu_fila(f);
            break;

        case 0:
            printf("\nVoce escolheu sair!!!");
            break;

        default:
            printf("\nDigite um opcao valida!");
            menu_fila(f);
            break;
    }
}
