#ifndef _patio1
    #define _patio1

    #include "carro.h"


    typedef struct _vagaP1 {
        carro atual;
        carro *prox;
    } vagaP1;

    typedef struct _patio1 {
        vagaP1* topo;
    } p1;

    void p1_criar(p1 *p);
    int p1_estaCheio(p1 *p); 
    int p1_estaVazio(p1 *p);
    int p1_inserir(p1 *p, vagaP1 *x);
    int p1_remover(p1 *p, vagaP1 *x);
#endif