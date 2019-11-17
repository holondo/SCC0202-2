typedef char elem;
typedef struct no No;
typedef struct lista Lista;

void cria(Lista **l);
void destroi(Lista **l);
void insere_inicio(Lista *l, elem x);
void insere_final(Lista *l, elem x);
void imprime(Lista *l);
int tamanho(Lista *l);
int tamanho2(Lista *l);
int esta_na_lista(Lista *l, elem x);
int esta_na_lista2(Lista *l, elem x);
int remover(Lista *l, elem x);
int remover2(Lista *l, elem x);
