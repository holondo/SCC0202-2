#include <stdlib.h>
#include <stdio.h>
#include "colecao.h"
/*
#include "lo.h"
#include "lu.h"
#include "lp.h"
#include "avl.h"
#include "abb.h"
*/

Colecao* cria_colecao(int estrutura_id) 
{
    Colecao *aux = malloc(sizeof(Colecao));
    aux->inicio = NULL;
    aux->estrutura_id = estrutura_id;

    return aux;
}

No* cria_no(int valor)
{
    No *aux = malloc(sizeof(No));
    aux->altura = -1;
    aux->dir = NULL;
    aux->esq = NULL;
    aux->valor = valor;

    return aux;
}

void adiciona(Colecao* c, int valor)
{
    switch (c->estrutura_id) {
        case 1:
            insere_LO();
            break;
        
        case 2:
            insere_LU();
            break;
        
        case 3:
            insere_LP();
            break;
        
        case 4:
            insere_ABB();
            break;
        
        case 5:
            insere_AVL();
            break;
    }
}

void destroi(Colecao* c)
{
   switch (c->estrutura_id)
    {
        case 1:// Lista ordenada

            break;
        
        case 2://Lista c. inserção na ultima pos.

            break;

        case 3:// Lista c. inserção na primeira pos.

            break;
        
        case 4:// Arvore binaria de busca.

            return destroi_arv(c->inicio);
            c->estrutura_id = -1;
            break;

        case 5:// Arvore AVL

            return destroi_arv(c->inicio);
            c->estrutura_id = -1;
            break;
            
    }
}

int existe(Colecao* c, int valor)
{
    switch (c->estrutura_id)
    {
        case 1:// Lista ordenada

            break;
        
        case 2://Lista c. inserção na ultima pos.

            break;

        case 3:// Lista c. inserção na primeira pos.

            break;
        
        case 4:// Arvore binaria de busca.

            return busca_arv(c->inicio);
            c->estrutura_id = -1;
            break;

        case 5:// Arvore AVL

            return busca_arv(c->inicio);
            c->estrutura_id = -1;
            break;
            
    }
}
