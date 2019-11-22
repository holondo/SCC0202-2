#include "colecao.h"
#include <stdlib.h>
#include <stdio.h>

void inserir_LO(No *ini, No *n) {

    if (ini == NULL) {
        ini = n;
        n->esq = NULL;
        n->dir = NULL;
        return;
    }

    //Ponteiro para percorrer a lista
    No *aux = ini;
    //
    while (aux->dir != NULL || n->valor < aux->valor) 
       aux = aux->dir;    

    if (aux->esq == NULL) { //Elemento na ponta esquerda
        n->esq = NULL;
        n->dir = aux;
        aux->esq = n;

    } else if (aux->dir != NULL) { //Elemento entre pontas
        No *aux_a = aux->esq;
        n->dir = aux;
        aux->esq = n;

        aux_a->dir = n;
        n->esq = aux_a;

    } else { //Elemento na ponta direita
        aux->dir = n;
        n->esq = aux;
        n->dir = NULL;
    }    
}

void inserir_LP(No *ini, No *n) {
    n->esq = NULL;
    n->dir = ini;
    ini->esq = n;
}

void inserir_LU(No *ini, No *n) {
    No *aux = ini;
    while (aux->dir != NULL)
        aux = aux->dir;
    aux->dir = n;
    n->dir = NULL;
    n->esq = aux;
    
}

int buscar_LI(No *ini, elem x) {

    No *aux = ini;
    while (aux != NULL) {
        if (aux->valor == x)
            return 1; //valor existe
        aux = aux->dir;
    }

    return 0; //Valor não existe
}

void imprimir_LI(No *ini) {
    No *aux = ini;
    while (aux != NULL) {
        printf("[%d]->", aux->valor);
        aux = aux->dir;
    }
}

void destruir_LI(No *ini) {
    No *aux;
    do {
        aux = ini;
        ini = ini->dir;
        free(aux);
    } while (aux != NULL);
}