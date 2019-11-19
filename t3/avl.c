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

int atualiza_Altura(No *n)
{
    if(n == NULL) return -1;

    n->altura = atualiza_Altura(n->dir) >= atualiza_Altura(n->esq) ? atualiza_Altura(n->dir) + 1 : atualiza_Altura(n->esq) + 1;
    return n->altura;
}

int altura_Sub(No *n)
{
    if( n == NULL) return 0;
    else
    {
        return n->altura;
    }    
}

int fator_Sub(No *n)
{
    if(n == NULL) return 0;

    return (altura_Sub(n->esq) - altura_Sub(n->dir));
}
No* esq(No *n)
{
	No *B = n->dir;

	
    n->dir = B->esq;
	B->esq = n;
	return B;
}

No* dir(No *n)
{
	No *B = n->esq;

	n->esq = B->dir;
	B->dir = n;
	return B;
}

No* dir_esq(No *n)
{
    n->dir = dir(n->dir);
    return esq(n);
}

No* esq_dir(No *n)
{
    n->esq = esq(n->esq);
    return dir(n);
}

No* dir_esq(No *n)
{
    dir(n->dir);
    return esq(n->esq);
}

No* balancea_AVL(Colecao *c, No *n)
{
    if(n == NULL) return n;

    if( fator_Sub(n) == 2 && fator_Sub(n->dir) >= 0)return esq(n);//Rotação p/ esquerda
    else if(fator_Sub(n) == 2 && fator_Sub(n->dir) == -1)return dir_esq(n);//rotação direita esquerda
    else if(fator_Sub(n) == -2 && fator_Sub(n->esq) <= 0)return dir(n); //rotação direita
    else if(fator_Sub(n) == -2 && fator_Sub(n->esq) == 1)return esq_dir(n); //rotação esquerda direita

    n->dir = balancea_AVL(c, n->dir);
    n->esq = balancea_AVL(c, n->esq);

    return n;
}

void insere_AVL(Colecao *c, No *n)
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
        //free aux

        if(n->valor > aux->valor)
        {
            if(aux->dir == NULL)
            {
                aux->dir = n;
                atualiza_Altura(c->inicio);
                c->inicio = balancea_AVL(c, c->inicio);
                atualiza_Altura(c->inicio);
            }
            aux = aux->dir;
        }

        else if(n->valor < aux->valor)
        {
            if(aux->esq == NULL)
            {
                aux->esq = n;
                atualiza_Altura(c->inicio);
                c->inicio = balancea_AVL(c, c->inicio);
                atualiza_Altura(c->inicio);
            }
            aux = aux->esq;
        }
    }
}

void destroi_AVL(No *n)
{
    if(n == NULL) return;

    destroi_AVL(n->dir);
    destroi_AVL(n->esq);

    free(n);
}