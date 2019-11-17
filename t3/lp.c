#include <stdlib.h>
#include <stdio.h>
#include "lp.h"

struct _no {
    elem info;
    struct no *prox;
};

struct _lp {
    No *ini, *fim;
};

void cria_lp(Lp **l) {
    // l   => Lp **
    // *l  => Lp *
    // **l => Lp
    *l = malloc(sizeof(Lp)); // instancia Lp
    // define Lp vazia
    (*l)->ini = NULL;
    (*l)->fim = NULL;
    return;
}

void destroi_lp(Lp **l) {
    // apaga elementos
    No *aux;
    while ((*l)->ini != NULL) {
        aux = (*l)->ini;
        (*l)->ini = (*l)->ini->prox;
        free(aux);
    }
    // apaga Lp
    free(*l);
    *l = NULL;
    return;
}

// insere no inicio
void insere_lp(Lp *l, elem x) {
    No *aux;
    // cria no
    aux = malloc(sizeof(No));
    aux->info = x;
    aux->prox = l->ini;
    // atualiza Lp
    l->ini = aux;
    if (l->fim == NULL)
        l->fim = aux;
    return;
}


void imprime_lp(Lp *l) {
    No *aux = l->ini;
    while (aux != NULL) {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

int busca_lp(Lp *l, elem x) {
    No *aux = l->ini;
    while (aux != NULL) {
        if (aux->info == x)
            return 1; // achou
        aux = aux->prox;
    }
    return 0; // nao achou
}


