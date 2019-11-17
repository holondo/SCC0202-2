#include "ab.h"
#include <stdlib.h>
#include <stdio.h>

struct no {
    elem info;
    struct no *esq, *dir;
};

struct ab {
    No *raiz;
};

void criar(Ab **a) {
    *a = malloc(sizeof(Ab));
    (*a)->raiz = NULL;
    return;
}

int estaVazia(Ab *a) {
    return (a->raiz == NULL);
}

No * buscarNo(No *n, elem x) {
    No *aux;
    if (n == NULL || n->info == x)
        return n; // fim; achou elemento ou subarvore vazia
    aux = buscarNo(n->esq, x);
    return (aux != NULL) ? aux : buscarNo(n->dir,x);
    /*if (aux != NULL)
        return aux;
    else
        return buscarNo(n->dir,x);*/
}

No * buscar(Ab *a, elem x) {
    return buscarNo(a->raiz, x); // inicia recursao
}

No * buscarNoPai(No *n, elem x) {
    No *aux;
    if ( n == NULL ||
         (n->esq != NULL && n->esq->info == x) ||
         (n->dir != NULL && n->dir->info == x) )
        return n; // fim; achou elemento ou subarvore vazia
    aux = buscarNoPai(n->esq, x);
    return (aux != NULL) ? aux : buscarNoPai(n->dir,x);
    /*if (aux != NULL)
        return aux;
    else
        return buscarNo(n->dir,x);*/
}

No * buscarPai(Ab *a, elem x) {
    return buscarNoPai(a->raiz, x); // inicia recursao
}

// cria nova caixa com dados recebidos por parametro
No *criarNo(elem x, No *esq, No *dir) {
    No *nova = malloc(sizeof(No));
    nova->info = x;
    nova->esq = esq;
    nova->dir = dir;
    return nova;
}

int inserirRaiz(Ab *a, elem x) {
    if (a->raiz != NULL)
        return 1; // erro, raiz ja existe
    a->raiz = criarNo(x, NULL, NULL); // cria nova caixa
    return 0; // sucesso
}

int inserirFilhoEsquerdo(Ab *a, elem x, elem infoPai) {
    No *pai = buscar(a, infoPai);
    if (pai == NULL || pai->esq != NULL)
        return 1; // erro, pai nao existe ou ja tem filho esquerdo
    pai->esq = criarNo(x, NULL, NULL);
    return 0; // sucesso
}

int inserirFilhoDireito(Ab *a, elem x, elem infoPai) {
    No *pai = buscar(a, infoPai);
    if (pai == NULL || pai->dir != NULL)
        return 1; // erro, pai nao existe ou ja tem filho direito
    pai->dir = criarNo(x, NULL, NULL);
    return 0; // sucesso
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

void imprimir(Ab *a) {
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

void destruir(Ab **a) {
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

int altura(Ab *a) {
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

void preOrdem(Ab *a) {
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

void emOrdem(Ab *a) {
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

void posOrdem(Ab *a) {
    posOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
    return;
}
