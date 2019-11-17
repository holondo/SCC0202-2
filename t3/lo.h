#ifndef lo_h
    #define lo_h
    
    typedef char elem;
    typedef struct _no No;
    typedef struct _lo Lo;

    void criar_LO(Lo **l);
    int inserir_LO(Lo *l, elem x);
    int buscar_LO(Lo *l, elem x);
    void imprimir_LO(Lo *l);
    void destruir_LO(Lo **l);
#endif