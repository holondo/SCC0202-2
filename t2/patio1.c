#include "patio1.h"

void p1_criar(p1 *p) {
    p->topo = NULL;
    return;
}

int p1_estaCheio(p1 *p) {
    int cont = 0;
    vagaP1 *aux = p->topo;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return(cont == 5 ? 1 : 0);
}

int p1_estaVazio(p1 *p) {
    return(p->topo == NULL ? 1 : 0);
}

int p1_inserir(p1 *p, carro x) { //vagaP1 x deve ser uma variável dinâmica
    if (p1_estaCheio(p))
        return 0; //erro pilha cheia
    vagaP1 *aux = malloc(sizeof(vagaP1));
    aux->atual = x;
    aux->prox = p->topo;
    p->topo = aux;    
    return 1; //sucesso
}


int p1_remover(p1 *p) {
    if (p1_estaVazio(p))
        return 0; //erro pilha vazia

    vagaP1 *aux = p->topo;
    p->topo = p->topo->prox;

    free(aux);
    return 1; //sucesso
}