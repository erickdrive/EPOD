#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define TAM 256

typedef struct no{
	unsigned char caractere;
	int frequencia;
	struct no *esq, *dir, *proximo;
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;

void inicializa_tabela(unsigned int tab[]){
	int i;
	for(i = 0; i<TAM; i++)
		tab[i] = 0;
	
}

void preencher_tab_freq(unsigned char texto[], unsigned int tab[]){
	int i = 0;
	
	while(texto[i] != '\0'){
		tab[texto[i]]++;
		i++;
	}
}

void imprime_tam_freq(unsigned int tab[]){
	int i;
	
	printf("\tTabela de Frequência\n");
	for(i = 0; i < TAM;i++){
		if(tab[i] > 0)
			printf("\t%d = %u = %c\n",i,tab[i],i);
	}
}

void criar_lista(Lista *lista){
	lista->inicio = NULL;
	lista->tam=0;
}

void inserir_ordenado(Lista *lista, No *no){
	No *aux;
	
	if(lista->inicio == NULL){
		lista->inicio = no;
	}else if(no->frequencia < lista->inicio->frequencia){
		no->proximo = lista->inicio;
		lista->inicio = no;
	}else{
		aux = lista->inicio;
		while(aux->proximo && aux->proximo->frequencia <= no->frequencia)
	    	aux = aux->proximo;
	   no->proximo = aux->proximo;
	   aux->proximo = no;
	}		
	lista->tam ++;
}

void preencher_lista(unsigned int tab[], Lista *lista){
	int i;
	No *novo;
	for(i = 0; i < TAM; i++){
		if(tab[i] > 0){
			novo = malloc(sizeof(No));
			if(novo){
				novo->caractere = i;
				novo->frequencia = tab[i];
				novo->dir = NULL;
				novo->esq = NULL;
				novo->proximo = NULL;
				inserir_ordenado(lista, novo);
			}else{
				printf("\nErro ao alocar memoria.\n");
				break;
			}
		}
	}
}

void imprimir_lista(Lista *lista){
	No *aux = lista->inicio;
	
	printf("\nLista Ordenada: Tamanho: %d\n",lista->tam);
	while(aux){
		printf("\nCaractere: %c Frequencia: %d\n", aux->caractere, aux->frequencia);
		aux = aux->proximo;
	}
}

No* remover_inicio(Lista *lista){
	No *aux = NULL;
	
	if(lista->inicio){
		aux = lista->inicio;
		lista->inicio = aux->proximo;
		aux->proximo = NULL;
		lista->tam--;
	}
	return aux;
}

No* montar_arvore(Lista *lista){
	No *primeiro, *segundo, *novo;
	while(lista->tam > 1){
		primeiro = remover_inicio(lista);
		segundo = remover_inicio(lista);
		novo = malloc(sizeof(No));
		
		if(novo){
			novo->caractere = '+';
			novo->frequencia = primeiro->frequencia + segundo->frequencia;
			novo->esq = primeiro;
			novo->dir = segundo;
			novo->proximo = NULL;
			inserir_ordenado(lista, novo);
		}else{
			printf("\nErro ao alocar memória.\n");
			break;
		}
	}
	return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam){
	if(raiz->esq == NULL && raiz->dir == NULL)
		printf("\tFolha: %c\tAltura: %d\n", raiz->caractere, tam);
	else{
		imprimir_arvore(raiz->esq, tam+1);
		imprimir_arvore(raiz->dir, tam+1);
	}
}

int altura(No *raiz){
	int esq, dir;
	
	if(raiz == NULL)
		return -1;
	else{
		esq = altura(raiz->esq) + 1;
		dir = altura(raiz->dir) + 1;
		
		if(esq > dir)
			return esq;
		else
			return dir;
	}
}

char** aloca_dicionario(int colunas){
	char **dicionario;
	int i;
	
	dicionario = malloc(sizeof(char*) * TAM);
	
	for(i = 0; i < TAM; i++)
		dicionario[i] = calloc(colunas, sizeof(char));
	
	return dicionario;		
}

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas){
	char esquerda[colunas], direita[colunas];
	
	if(raiz->esq == NULL && raiz->dir == NULL)
		strcpy(dicionario[raiz->caractere], caminho);
	else{
		strcpy(esquerda, caminho);
		strcpy(direita, caminho);
		
		strcat(esquerda, "0");
		strcat(direita, "1");
		
		gerar_dicionario(dicionario, raiz->esq,  esquerda, colunas);
		gerar_dicionario(dicionario, raiz->dir,  direita, colunas);
	}	
}


int main(void){
	unsigned char texto[] = "Vamos aprender a programar";
	unsigned int tab_freq[TAM];
	Lista lista;
	No *arvore;
	int colunas;
	char **dicionario;
	char *codificado, *decodificado;
	setlocale(LC_ALL,"Portuguese");
	
	inicializa_tabela(tab_freq);
	preencher_tab_freq(texto, tab_freq);
	imprime_tam_freq(tab_freq);
	
	criar_lista(&lista);
	preencher_lista(tab_freq, &lista);
	imprimir_lista(&lista);
	
	arvore = montar_arvore(&lista);
	printf("\n\tArvore de Huffman\n");
	imprimir_arvore(arvore, 0);
	
}