#include "abb.h"

int busca_arv(No *a, int n)
{   
    if(a == NULL) return -1;
    if(a->valor == n) return n;

    if(n > a->valor) return valorABB(a->dir, n);
    else if(n < a->valor) return valorABB(a->esq, n);
}

int insere_ABB(Colecao *c, No *n)
{
    if(c->inicio == NULL)
    {
        c->inicio = n;
        return;
    }

    No *aux = c->inicio;

    while (aux != NULL || aux != n)
    {
        if(n->valor == aux->valor) return;

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

    void destroi_arv(No *n)
    {
        if(n == NULL) return;

        destroi_arv(n->dir);
        destroi_arv(n->esq);

        free(n);
    }