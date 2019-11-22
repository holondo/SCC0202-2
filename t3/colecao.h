#ifndef __COLECAO__
    #define __COLECAO__

    typedef int elem;

    #define LISTA_ORDENADO 1
    #define LISTA_ULTIMO   2
    #define LISTA_PRIMEIRO 3
    #define ARVORE_BINARIA 4
    #define ARVORE_AVL     5

    typedef struct _no
    {
        elem valor;
        struct _no* esq;
        struct _no* dir;
        int altura; // Usado somente na AVL
    }No;

    typedef struct _c
    {
        No* inicio;
        int estrutura_id;
    }Colecao;

    Colecao* cria_colecao(int estrutura_id);
    
    No* cria_no(int valor);
    void adiciona(Colecao* c, int valor);
    int existe(Colecao* c, int valor);
    void destroi(Colecao* c);

#endif