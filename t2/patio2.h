#ifndef _patio2
    #define _patio2
    #include "carro.h"


    typedef struct _vagaP2 {
        carro atual;
        carro *prox;
    } vagaP2;

    typedef struct _patio2 {
        vagaP2* ini, *fim;
    } p2;

    void p2_criar(p2 *p);
    int p2_estaCheio(p2 *p); 
    int p2_estaVazio(p2 *p);
    int p2_inserir(p2 *p, carro x);
    int p2_remover(p2 *p);


#endif