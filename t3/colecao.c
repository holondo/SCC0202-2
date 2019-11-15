#include "colecao.h"
#include <stdlib.h>


colecao* criar_colecao(int opcao) {
    colecao *aux = malloc(sizeof(colecao));
    aux->ini = NULL;
    aux->tipo = opcao;

    return aux;
}

no* criar_no(elem valor) {
    no *aux = malloc(sizeof(no));
    aux->altura = -1;
    aux->no_dir = NULL;
    aux->no_esq = NULL;
    aux->valor = valor;

    return aux;
}

void add_valor(colecao *c, no* n) {

    switch (c->tipo) {
        case 1:
            insere_LO();
            break;
        
        case 2:
            insere_LU();
            break;
        
        case 3:
            insere_LP();
            break;
        
        case 4:
            insere_ABB();
            break;
        
        case 5:
            insere_AVL();
            break;
    }
}
