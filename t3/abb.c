#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int busca_ABB(No *a, int n)
{   
    if(a == NULL) return -1;
    if(a->valor == n) return n;

    if(n > a->valor) return busca_ABB(a->dir, n);
    else if(n < a->valor) return busca_ABB(a->esq, n);
    return -1;
}

void insere_ABB(Colecao *c, No *n)
{
    if(c->inicio == NULL)
    {
        c->inicio = n;
        return;
    }

    No *aux = c->inicio;

    while (aux != NULL || aux != n)
    {
        n->altura++;
        if(n->valor == aux->valor) return;
        //free aux
        if(n->valor > aux->valor)
        {
            if(aux->dir == NULL) aux->dir = n;
            aux = aux->dir;
        }

        else if(n->valor < aux->valor)
        {
            if(aux->esq == NULL) aux->esq = n;
            aux = aux->esq;
        }
    }
}

void destroi_ABB(No *n)
{
    if(n == NULL) return;

    destroi_ABB(n->dir);
    destroi_ABB(n->esq);

    free(n);
}