#include <stdio.h>
#include "menu.h"
#include "fila.h"
#include "pilha.h"

void menu_fila(LFP *f){
    int op, n;

    printf("\n***** Menu (Fila) *****");
    
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
            insere_inicio(f,n);
            mostra(*f);
            menu_fila(f);
            break;
        
        case 2:
            pop_f(f);
            mostra(*f);
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

void menu_pilha(LFP *p){
    int op, n;

    printf("\n***** Menu (Pilha) *****");
    
    //printf("1 - Criar fila;"); \\ Tem que ser feito no programa main
    printf("\n1 - Inserir elemento;");
    printf("\n2 - Remover elemento;");
    printf("\n3 - Mostrar fila;");
    printf("\n0 - Encerrar");
    
    printf("\n\tSelcione a opcao desejada: ");
    scanf("%d",&op);

    switch(op){
        case 1:
            printf("\nDigite um valor para a pilha: ");
            scanf("%d",&n);
            insere_inicio(p,n);
            mostra(*p);
            menu_pilha(p);
            break;
        
        case 2:
            pop_p(p);
            menu_pilha(p);
            break;

        case 3:
            mostra(*p);
            menu_pilha(p);
            break;

        case 0:
            printf("\nVoce escolheu sair!!!");
            break;

        default:
            printf("\nDigite um opcao valida!");
            menu_pilha(p);
            break;
    }
}
