#ifndef lo_h
    #define lo_h

    #include "colecao.h"
    
    void inserir_LO(Colecao *c, No *n); 
    void inserir_LP(Colecao *c, No *n); 
    void inserir_LU(Colecao *c, No *n); 
    int buscar_LI(No *ini, elem x);
    void imprimir_LI(No *ini);
    void destruir_LI(No *ini);

#endif
