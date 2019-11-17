#ifndef lo_h
    #define lo_h
    
    typedef char elem;
    typedef struct bloco Bloco;
    typedef struct listaOrd ListaOrd;

    void criar_LO(ListaOrd **l);
    int inserir_LO(ListaOrd *l, elem x);
    int remover_Lo(ListaOrd *l, elem x);
    int buscar_LO(ListaOrd *l, elem x);
    void imprimir_LO(ListaOrd *l);
    void destruir_LO(ListaOrd **l);
#endif