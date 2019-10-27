#include "patio2.h"

void p2_criar(p2 *p) {
    p->ini = NULL;
    p->fim = NULL;
    return;
}

int p2_estaCheio(p2 *p) {
    int cont = 0;
    vagaP2 *aux = p->ini;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return(cont == 10 ? 1 : 0);
}

int p2_estaVazio(p2 *p) {
    return(p->ini == NULL ? 1 : 0);
}

int p2_inserir(p2 *p, carro c) { //vagaP2 x deve ser uma variável dinâmica
    if (p2_estaCheio(p))
        return 0; //erro pilha cheia
    vagaP2 *aux = malloc(sizeof(vagaP2));
    aux->atual = c;
    aux->prox = NULL;

    if(p->ini != 0)
    {
        p->fim->prox = aux;
        p->fim = aux;
    }
    else
    {
        p->ini = aux;
        p->fim = aux;
    }
    return 1;    
}


int p2_remover(p2 *p) {
    if (p1_estaVazio(p))
        return 0; //erro pilha vazia

    vagaP2 *aux = p->ini;
    p->ini = p->ini->prox;

    free(aux);

    return 1; //sucesso
}