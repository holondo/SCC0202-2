#ifndef lu_h
    #define lu_h

    typedef char elem;
    typedef struct _no No;
    typedef struct _lu Lu;

    void cria_lu(Lu **l);
    void destroi_lu(Lu **l);
    void insere_lu(Lu *l, elem x);
    void imprime_lu(Lu *l);
    int busca_lu(Lu *l, elem x);
    

#endif