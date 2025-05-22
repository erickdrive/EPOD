#ifndef ARVORE
#define ARVORE

typedef struct no{
	int valor;
	struct no *direita, *esquerda;
}NoArv;

NoArv *inserir_v1(NoArv *raiz, int num);
void imprimir_pre_ordem(NoArv *raiz);
void imprimir_in_ordem(NoArv *raiz);
void imprimir_pos_ordem(NoArv *raiz);
void inserir_v2(NoArv **raiz, int num);
void inserir_v3(NoArv **raiz, int num);
NoArv *buscar_v1(NoArv *raiz, int num);
NoArv *buscar_v2(NoArv *raiz, int num);
int altura(NoArv *raiz);
int quantidade_nos(NoArv *raiz);
int quantidade_folhas(NoArv *raiz);
NoArv* remover(NoArv *raiz, int chave);


#endif
