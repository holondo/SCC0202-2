#include "avl.h"

void insere_ABB(colecao *c, no *n) {

    if(c->ini == NULL){
        c->ini = n;
        return;
    }
    
    no *aux = c->ini;

    while (aux != NULL || aux != n)
    {
        if(n->valor == aux->valor) return;

        if(n->valor > aux->valor) {
            if(aux->no_dir == NULL) aux->no_dir = n;
            aux = aux->no_dir;
        }

        else if(n->valor < aux->valor) {
            if(aux->no_esq == NULL) aux->no_esq = n;
            aux = aux->no_esq;
        }
    }
}

int valor_arv(no *a, int n) {   
    if(a == NULL) return -1;
    if(a->valor == n) return n;

    if(n > a->valor) return valorABB(a->no_dir, n);
    else if(n < a->valor) return valorABB(a->no_esq, n);
}

void destroi_arv(no *n) {

    if(n == NULL) return;

    destroi_arv(n->no_dir);
    destroi_arv(n->no_esq);

    free(n);
}
