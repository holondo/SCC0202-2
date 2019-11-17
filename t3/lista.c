#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct no {
    elem info;
    struct no *prox;
};

struct lista {
    No *ini, *fim;
};

void cria(Lista **l) {
    // l   => Lista **
    // *l  => Lista *
    // **l => Lista
    *l = malloc(sizeof(Lista)); // instancia lista
    // define lista vazia
    (*l)->ini = NULL;
    (*l)->fim = NULL;
    return;
}

void destroi(Lista **l) {
    // apaga elementos
    No *aux;
    while ((*l)->ini != NULL) {
        aux = (*l)->ini;
        (*l)->ini = (*l)->ini->prox;
        free(aux);
    }
    // apaga lista
    free(*l);
    *l = NULL;
    return;
}

// insere no inicio
void insere_inicio(Lista *l, elem x) {
    No *aux;
    // cria no
    aux = malloc(sizeof(No));
    aux->info = x;
    aux->prox = l->ini;
    // atualiza lista
    l->ini = aux;
    if (l->fim == NULL)
        l->fim = aux;
    return;
}

void insere_final(Lista *l, elem x) {
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

void imprime(Lista *l) {
    No *aux = l->ini;
    while (aux != NULL) {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

int tamanho(Lista *l) {
    No *aux = l->ini;
    int contagem = 0;
    while (aux != NULL) {
        contagem++;
        aux = aux->prox;
    }
    return contagem;
}

int tamanho_rec(No *p) {
    if (p == NULL)
        return 0; // lista vazia
    return 1 + tamanho_rec(p->prox);
}

int tamanho2(Lista *l) {
    return tamanho_rec(l->ini); // inicia recursao
}

int esta_na_lista(Lista *l, elem x) {
    No *aux = l->ini;
    while (aux != NULL) {
        if (aux->info == x)
            return 1; // achou
        aux = aux->prox;
    }
    return 0; // nao achou
}

int esta_na_lista2_rec(No *p, elem x) {
    if (p == NULL)
        return 0; // nao esta na lista
    if (p->info == x)
        return 1; // achou
    return esta_na_lista2_rec(p->prox,x);
}
    
int esta_na_lista2(Lista *l, elem x) {
    return esta_na_lista2_rec(l->ini,x);
}

int remover(Lista *l, elem x) {
    No *atual, *ant;
    atual = l->ini;
    ant = NULL;
    while (atual != NULL) {
        if (atual->info == x) { // encontrou, entao apaga
            if (ant == NULL)
                l->ini = atual->prox; // inicio
            else
                ant->prox = atual->prox; // meio ou fim
            if (atual == l->fim)
                l->fim = ant; // para quando removeu o ultimo
            free(atual); // apaga
            return 1; // sucesso
        }
        ant = atual;
        atual = atual->prox;
    }
    return 0; // nao achou
}

int remover2_rec(No *atual, No *ant, elem x, Lista *l) {
    if (atual == NULL)
        return 0; // nao achou
    if (atual->info == x) { // achou, entao remove
        if (ant == NULL)
            l->ini = atual->prox; // inicio
        else
            ant->prox = atual->prox; // meio ou fim
        if (atual == l->fim)
            l->fim = ant; // para quando removeu o ultimo
        free(atual); // apaga
        return 1; // sucesso
    }
    return remover2_rec(atual->prox, atual, x, l);
}

int remover2(Lista *l, elem x) {
    return remover2_rec(l->ini, NULL, x, l); // inicia recursao
}
