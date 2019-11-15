#ifndef colecao_h
    #define colecao_h

    typedef int elem;

    typedef struct _no {
        elem valor;
        struct _no *no_esq, *no_dir;
        int altura;
    } no;

    typedef struct _collection {
        int tipo;  // Define o tipo de estrutura
        no* ini; //Aponta para o nó inicial
    } colecao;


    colecao* criar_colecao(int opcao);
    /*
        Função que inicializa a colecao conforme a estrutura especificada
        Return - colecao [tipo = opcao e ini = NULL]
        Argumentos - 
        opcao - [0 - Lista ordenada; 1 - Lista insercao ultima pos; 2- Lista insercao primeira pos
                3 - Árvore binária de busca; 4 - Árvore AVL]
    */

    no* criar_no(elem valor);

    void add_valor(colecao *c, no* n);

    int existe_no(colecao *c, elem valor);

    void destruir_colecao(colecao *c);

#endif