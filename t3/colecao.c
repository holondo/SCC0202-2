#include <stdlib.h>
#include <stdio.h>
#include "colecao.h"
#include "li.h"
#include "avl.h"
#include "abb.h"

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
    No *n = cria_no(valor);
    switch (c->estrutura_id) {
        case 1:
            inserir_LO(c, n);
            break;
        
        case 2:
            inserir_LU(c, n);
            break;
        
        case 3:
            inserir_LP(c, n);
            break;
        
        case 4:
            insere_ABB(c,n);
            break;
        
        case 5:
            insere_AVL(c, n);
            break;
    }
}

void destroi(Colecao* c)
{
   switch (c->estrutura_id)
    {
        case 1:// Lista ordenada
        case 2://Lista c. inserção na ultima pos.
        case 3:// Lista c. inserção na primeira pos.
            return destruir_LI(c);
            c->estrutura_id = -1;
            break;
        
        case 4:// Arvore binaria de busca.

            return destroi_ABB(c->inicio);
            c->estrutura_id = -1;
            break;

        case 5:// Arvore AVL

            return destroi_AVL(c->inicio);
            c->estrutura_id = -1;
            break;
            
    }
}

int existe(Colecao* c, int valor)
{
    switch (c->estrutura_id)
    {
        case 1:// Lista ordenada
        case 2://Lista c. inserção na ultima pos.
        case 3:// Lista c. inserção na primeira pos.
            return buscar_LI(c->inicio, valor);
            break;

        case 4:// Arvore binaria de busca.

            return busca_ABB(c->inicio, valor);
            break;

        case 5:// Arvore AVL

            return busca_AVL(c->inicio, valor);
            break;            
    }
    return -1;
}

void imprimir (Colecao *c) {
    switch(c->estrutura_id) {
        case 1:
        case 2:
        case 3:
            imprimir_LI(c->inicio);
            break;
        case 4:
            //imprimir_ABB();
            break;
        case 5:
            //imprimir_AVL();
            break;
    }
}