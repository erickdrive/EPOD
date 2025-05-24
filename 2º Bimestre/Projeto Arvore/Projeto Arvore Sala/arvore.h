#ifndef PONTO_COLETA
#define PONTO_COLETA

typedef struct PontoColeta{
	int codigo;
	char nome[100];
	char tipo_material[50];
	struct PontoColeta *esquerda;
	struct PontoColeta *direita;
}PontoColeta;

PontoColeta* inserir(PontoColeta* raiz, int codigo, char* nome, char* tipo_material);
PontoColeta* buscar(PontoColeta* raiz, int codigo);
void imprimir_em_ordem(PontoColeta* raiz);

#endif
