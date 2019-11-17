#include "abb.h"
#include <stdlib.h>
#include <stdio.h>

struct _no {
    elem info;
    struct _no *esq, *dir;
};

struct abb {
    No *raiz;
};

void criar(Abb **a) {
    *a = malloc(sizeof(Abb));
    (*a)->raiz = NULL;
    return;
}

int estaVazia(Abb *a) {
    return (a->raiz == NULL);
}

void imprimirSubarvore(No *p) {
    printf("{ ");
    if (p != NULL) {
        printf("%c , ", p->info); // imprime raiz
        imprimirSubarvore(p->esq);
        printf(", ");
        imprimirSubarvore(p->dir);
    }
    printf("} ");
    return;
}

void imprimir(Abb *a) {
    imprimirSubarvore(a->raiz);
    printf("\n");
    return;
}

void destruirNo(No *p) {
    if (p != NULL) {
        destruirNo(p->esq); // apaga lado esquerdo
        destruirNo(p->dir); // apaga lado direito
        free(p);
    }
    return;
}

void destruir(Abb **a) {
    destruirNo((*a)->raiz); // apaga nos
    free(*a); // apaga ponteiro do raiz
    *a = NULL; // apaga ligacao do usuario com a regiao de mem da arvore
    return;
}

int alturaSubarvore(No *p) {
    int aesq, adir;
    if (p == NULL)
        return 0; // subarvore nula
    aesq = alturaSubarvore(p->esq);
    adir = alturaSubarvore(p->dir);
    return (aesq > adir) ? aesq + 1 : adir + 1;
    //if (aesq > adir)
    //    return aesq + 1;
    //else
    //    return adir + 1;
}

int altura(Abb *a) {
    return alturaSubarvore(a->raiz);
}

void imprimirFilhoEsquerdo(No *p) {
    if (p != NULL && p->esq != NULL)
        printf("%c ", p->esq->info);
    return;
}

void imprimirFilhoDireito(No *p) {
    if (p != NULL && p->dir != NULL)
        printf("%c ", p->dir->info);
    return;
}

void imprimirNo(No *p) {
    if (p != NULL)
        printf("%c ", p->info);
    return;
}

void preOrdemRecursivo(No *p) {
    if (p == NULL)
        return; // subarvore vazia
    printf("%c ", p->info); // processa no
    preOrdemRecursivo(p->esq); // processa lado esquerdo
    preOrdemRecursivo(p->dir); // processa lado direito
    return;
}

void preOrdem(Abb *a) {
    preOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
    return;
}

void emOrdemRecursivo(No *p) {
    if (p == NULL)
        return; // subarvore vazia
    emOrdemRecursivo(p->esq); // processa lado esquerdo
    printf("%c ", p->info); // processa no
    emOrdemRecursivo(p->dir); // processa lado direito
    return;
}

void emOrdem(Abb *a) {
    emOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
    return;
}

void posOrdemRecursivo(No *p) {
    if (p == NULL)
        return; // subarvore vazia
    posOrdemRecursivo(p->esq); // processa lado esquerdo
    posOrdemRecursivo(p->dir); // processa lado direito
    printf("%c ", p->info); // processa no
    return;
}

void posOrdem(Abb *a) {
    posOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
    return;
}

int buscarSubarvore(No *p, elem x) {
    if (p == NULL)
        return 0; // nao achou
    if (p->info == x)
        return 1; // achou
    return (x < p->info) ? buscarSubarvore(p->esq, x) : buscarSubarvore(p->dir, x);
    //if (x < p->info)
    //    return buscarSubarvore(p->esq, x);
    //else
    //    return buscarSubarvore(p->dir, x);
}

int buscar(Abb *a, elem x) {
    return buscarSubarvore(a->raiz, x); // inicia recursividade
}

// cria nova caixa com dados recebidos por parametro
No *criarNo(elem x, No *esq, No *dir) {
    No *nova = malloc(sizeof(No));
    nova->info = x;
    nova->esq = esq;
    nova->dir = dir;
    return nova;
}

int inserirSubarvore(No **p, elem x) {
    if (*p == NULL) {
        *p = criarNo(x, NULL, NULL); // cria e atualiza ponteiros
        return 0; // sucesso
    }
    if ((*p)->info == x)
        return 1; // erro, elemento ja existe
    return (x < (*p)->info) ? inserirSubarvore( &((*p)->esq), x) : inserirSubarvore( &((*p)->dir), x);
}

int inserir(Abb *a, elem x) {
    return inserirSubarvore(&(a->raiz), x); // inicia recursividade
}

int removerSubarvore(No **p, elem x) {
    int numFilhos = 0;
    No *aux, paiAux;
    if (*p == NULL)
        return 1; // erro, elemento nao existe
    if ((*p)->info == x) { // remove
        // conta filhos
        if ((*p)->esq != NULL)
            numFilhos++;
        if ((*p)->dir != NULL)
            numFilhos++;
        switch (numFilhos) {
            case 0: // nenhum filho
                free(*p);
                *p = NULL;
                break;
            case 1: // um filho
                aux = *p;
                *p = ((*p)->esq != NULL) ? (*p)->esq : (*p)->dir;
                free(aux);
                break;
            case 2: // dois filhos
                // acha maior da esquerda
                aux = (*p)->esq; // um passo para a esquerda
                paiAux = *p;
                while (aux->dir != NULL) { // segue indefinidamente a direita
                    paiAux = aux;
                    aux = aux->dir;
                }
                (*p)->info = aux->info; // troca informacao
                removerSubarvore( (paiAux == *p) ? &(paiAux->esq) : &(paiAux->dir) , aux->info); // remove substituto
                break;
        }
    }
    return (x < (*p)->info) ? removerSubarvore( &((*p)->esq), x) : removerSubarvore( &((*p)->dir), x);
}

int remover(Abb *a, elem x) {
    return removerSubarvore(&(a->raiz), x); // inicia recursividade
}
