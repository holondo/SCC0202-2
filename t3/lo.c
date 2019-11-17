#include "lo.h"
#include <stdlib.h>
#include <stdio.h>

struct _no {
    elem info;
    struct _no *prox;
};

struct _lo {
    No *ini;
};

void criar_LO(Lo **l) {
    *l = malloc(sizeof(Lo));
    (*l)->ini = NULL;
    return;
}

void busca_interna(Lo *l, elem x, No **p, No **ant) {
    *p = l->ini; // primeiro da lista
    *ant = NULL; // anterior do primeiro eh nulo
    while (*p != NULL && (*p)->info < x) {
        *ant = *p; // guarda anterior
        *p = (*p)->prox; // atualiza no corrente
    }
    return;
}

int inserir_LO(Lo *l, elem x) {
    No *p, *ant, *nova;
    
    busca_interna(l, x, &p, &ant); // busca posicao para insercao
    if (p != NULL && p->info == x)
        return 1; // erro, elemento ja existe
    
    // cria caixa e copia informacao
    nova = malloc(sizeof(No));
    nova->info = x;
    
    // atualiza encadeamento
    nova->prox = p;
    if (ant == NULL)
        l->ini = nova; // caso 1
    else
        ant->prox = nova; // caso 2
    
    return 0; // sucesso
}


int buscar_LO(Lo *l, elem x) {
    No *aux = l->ini;
    while (aux != NULL)
        if (aux->info >= x)
            return (aux->info == x); // encontrou ou nao
        else
            aux = aux->prox;
    return 0; // nao encontrou
}

void imprimir_LO(Lo *l) {
    No *aux;
    aux = l->ini;
    while (aux != NULL) {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void destruir_LO(Lo **l) {
    No *aux;
    while ((*l)->ini != NULL) {
        aux = (*l)->ini;
        (*l)->ini = (*l)->ini->prox;
        free(aux);
    }
    free(*l);
    *l = NULL;
    return;
}
