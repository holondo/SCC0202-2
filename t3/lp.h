#ifndef lp_h
    #define lp_h

    typedef int elem;
    typedef struct _no No;
    typedef struct _lp Lp;

    void cria_lp(Lp **l);
    void destroi_lp(Lp **l);
    void insere_lp(Lp *l, elem x);
    void imprime_lp(Lp *l);
    int busca_lp(Lp *l, elem x);
    

#endif