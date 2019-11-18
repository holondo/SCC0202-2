#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int busca_AVL(No *a, int n)
{   
    if(a == NULL) return -1;
    if(a->valor == n) return n;

    if(n > a->valor) return busca_AVL(a->dir, n);
    else if(n < a->valor) return busca_AVL(a->esq, n);
    return -1;
}

void insere_AVL(Colecao *c, No *n)
{
    
}

void destroi_AVL(No *n)
{
    if(n == NULL) return;

    destroi_AVL(n->dir);
    destroi_AVL(n->esq);

    free(n);
}