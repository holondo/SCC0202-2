#include "listaOrd.h"
#include <stdlib.h>
#include <stdio.h>

struct bloco {
    elem info;
    struct bloco *prox;
};

struct listaOrd {
    Bloco *ini;
};

void criar(ListaOrd **l) {
    *l = malloc(sizeof(ListaOrd));
    (*l)->ini = NULL;
    return;
}

void busca_interna(ListaOrd *l, elem x, Bloco **p, Bloco **ant) {
    *p = l->ini; // primeiro da lista
    *ant = NULL; // anterior do primeiro eh nulo
    while (*p != NULL && (*p)->info < x) {
        *ant = *p; // guarda anterior
        *p = (*p)->prox; // atualiza no corrente
    }
    return;
}

int inserir(ListaOrd *l, elem x) {
    Bloco *p, *ant, *nova;
    
    busca_interna(l, x, &p, &ant); // busca posicao para insercao
    if (p != NULL && p->info == x)
        return 1; // erro, elemento ja existe
    
    // cria caixa e copia informacao
    nova = malloc(sizeof(Bloco));
    nova->info = x;
    
    // atualiza encadeamento
    nova->prox = p;
    if (ant == NULL)
        l->ini = nova; // caso 1
    else
        ant->prox = nova; // caso 2
    
    return 0; // sucesso
}

int remover(ListaOrd *l, elem x) {
    Bloco *p, *ant;
    
    busca_interna(l, x, &p, &ant); // busca posicao para insercao
    if (p == NULL || p->info > x)
        return 1; // erro, elemento nao existe; casos 1, 2 e 4b
    
    // p aponta para caixa a ser removida
    if (ant == NULL)
        l->ini = p->prox; // remove no inicio; caso 3
    else
        ant->prox = p->prox; // remove no meio ou no final; caso 4a
    
    free(p); // libera memoria
    
    return 0; // sucesso
}

int buscar(ListaOrd *l, elem x) {
    Bloco *aux = l->ini;
    while (aux != NULL)
        if (aux->info >= x)
            return (aux->info == x); // encontrou ou nao
        else
            aux = aux->prox;
    return 0; // nao encontrou
}

void imprimir(ListaOrd *l) {
    Bloco *aux;
    aux = l->ini;
    while (aux != NULL) {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void destruir(ListaOrd **l) {
    Bloco *aux;
    while ((*l)->ini != NULL) {
        aux = (*l)->ini;
        (*l)->ini = (*l)->ini->prox;
        free(aux);
    }
    free(*l);
    *l = NULL;
    return;
}
