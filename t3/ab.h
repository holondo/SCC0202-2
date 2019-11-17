typedef char elem;
typedef struct no No;
typedef struct ab Ab;

void criar(Ab **a);
int estaVazia(Ab *a);
No *buscar(Ab *a, elem x);
No *buscarPai(Ab *a, elem x);
int inserirRaiz(Ab *a, elem x);
int inserirFilhoEsquerdo(Ab *a, elem x, elem infoPai);
int inserirFilhoDireito(Ab *a, elem x, elem infoPai);
void imprimir(Ab *a);
void destruir(Ab **a);
int altura(Ab *a);
void imprimirNo(No *p);
void imprimirFilhoEsquerdo(No *p);
void imprimirFilhoDireito(No *p);
void preOrdem(Ab *a);
void emOrdem(Ab *a);
void posOrdem(Ab *a);

