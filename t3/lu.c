#include <stdlib.h>
#include <stdio.h>
#include "lu.h"

struct _no {
    elem info;
    struct no *prox;
};

struct _lu {
    No *ini, *fim;
};

void cria_lp(Lu **l) {
    // l   => Lu **
    // *l  => Lu *
    // **l => Lu
    *l = malloc(sizeof(Lu)); // instancia Lu
    // define Lu vazia
    (*l)->ini = NULL;
    (*l)->fim = NULL;
    return;
}

void destroi_lp(Lu **l) {
    // apaga elementos
    No *aux;
    while ((*l)->ini != NULL) {
        aux = (*l)->ini;
        (*l)->ini = (*l)->ini->prox;
        free(aux);
    }
    // apaga Lu
    free(*l);
    *l = NULL;
    return;
}

//insere no final
void insere_lu(Lu *l, elem x) {
    No *aux;
    // cria no
    aux = malloc(sizeof(No));
    aux->info = x;
    aux->prox = NULL;
    // atualiza ponteiros
    if (l->fim != NULL)
        l->fim->prox = aux;
    l->fim = aux;
    if (l->ini == NULL)
        l->ini = aux;
    return;
}

void imprime_lp(Lu *l) {
    No *aux = l->ini;
    while (aux != NULL) {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

int busca_lp(Lu *l, elem x) {
    No *aux = l->ini;
    while (aux != NULL) {
        if (aux->info == x)
            return 1; // achou
        aux = aux->prox;
    }
    return 0; // nao achou
}


