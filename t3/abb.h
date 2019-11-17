typedef char elem;
typedef struct no No;
typedef struct abb Abb;

void criar(Abb **a);
int estaVazia(Abb *a);
//No *buscar(Abb *a, elem x);
//No *buscarPai(Abb *a, elem x);
//int inserirRaiz(Abb *a, elem x);
//int inserirFilhoEsquerdo(Abb *a, elem x, elem infoPai);
//int inserirFilhoDireito(Abb *a, elem x, elem infoPai);
void imprimir(Abb *a);
void destruir(Abb **a);
int altura(Abb *a);
void imprimirNo(No *p);
void imprimirFilhoEsquerdo(No *p);
void imprimirFilhoDireito(No *p);
void preOrdem(Abb *a);
void emOrdem(Abb *a);
void posOrdem(Abb *a);
int buscar(Abb *a, elem x);
int inserir(Abb *a, elem x);
int remover(Abb *a, elem x);

