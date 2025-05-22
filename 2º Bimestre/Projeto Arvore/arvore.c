#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

NoArv *inserir_v1(NoArv *raiz, int num){
	if(raiz == NULL){
		NoArv *aux = malloc(sizeof(NoArv));
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		return aux;
	}else{
		if(num < raiz->valor)
			raiz->esquerda = inserir_v1(raiz->esquerda, num);
		else
			raiz->direita = inserir_v1(raiz->direita, num);
		return raiz;
	}
}
//--------------------------------------------------------------

void imprimir_pre_ordem(NoArv *raiz){
	if(raiz){
		printf("%d ", raiz->valor);
		imprimir_pre_ordem(raiz->esquerda);
		imprimir_pre_ordem(raiz->direita);
	}
}

//----------------------------------------------------------------

void imprimir_in_ordem(NoArv *raiz){
	if(raiz){
		imprimir_in_ordem(raiz->esquerda);
		printf("%d ", raiz->valor);
		imprimir_in_ordem(raiz->direita);
	}
}

//----------------------------------------------------------------
void imprimir_pos_ordem(NoArv *raiz){
	if(raiz){
		imprimir_pos_ordem(raiz->esquerda);
		imprimir_pos_ordem(raiz->direita);
		printf("%d ", raiz->valor);
	}
}

//----------------------------------------------------------------
void inserir_v2(NoArv **raiz, int num){
	if(*raiz == NULL){
		*raiz = malloc(sizeof(NoArv));
		(*raiz)->valor = num;
		(*raiz)->esquerda = NULL;
		(*raiz)->direita = NULL;
	}else{
		if(num < (*raiz)->valor)
			inserir_v2(&((*raiz)->esquerda), num);
		else
		    inserir_v2(&((*raiz)->direita), num);
	}
}
//--------------------------------------------------------
void inserir_v3(NoArv **raiz, int num){
	NoArv *aux = *raiz;
	while(aux){
		if(num < aux->valor)
			raiz = &aux->esquerda;
		else
			raiz = &aux->direita;
		aux = *raiz;
	}
	aux = malloc(sizeof(NoArv));
	aux->valor = num;
	aux->esquerda = NULL;
	aux->direita = NULL;
	*raiz = aux;

}

//------------------------------------------------------------
NoArv *buscar_v1(NoArv *raiz, int num){
	if(raiz){
		if(num == raiz->valor)
			return raiz;
	    else if(num < raiz->valor)
	      return buscar_v1(raiz->esquerda, num);
	    else
	      return buscar_v1(raiz->direita, num);
	}
	return NULL;
}

//---------------------------------------------------------------
NoArv *buscar_v2(NoArv *raiz, int num){
   while(raiz){
   	if(num < raiz->valor)
   	    raiz = raiz->esquerda;
   	else if(num > raiz->valor)
   	    raiz = raiz->direita;
   	else 
	   return raiz;
   }
	return NULL;
}

//-----------------------------------------------------------------
int altura(NoArv *raiz){
	if(raiz == NULL){
		return -1;
	}else{
		int esq = altura(raiz->esquerda);
		int dir = altura(raiz->direita);
		if(esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}
}

//-----------------------------------------------------------------
int quantidade_nos(NoArv *raiz){
	if(raiz == NULL)
		return 0;
	else
		return 1 +
		quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

//-----------------------------------------------------------------
int quantidade_folhas(NoArv *raiz){
	if(raiz == NULL)
		return 0;
	else if(raiz->esquerda == NULL && raiz->direita == NULL)
		return 1;
	else
		return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

//-----------------------------------------------------------------
NoArv* remover(NoArv *raiz, int chave){
	if(raiz == NULL){
		printf("\n Valor nao encontrado.\n");
		return NULL;
	}else{
		if(raiz->valor == chave){
			if(raiz->esquerda == NULL && raiz->direita == NULL){
				free(raiz);
				printf(" Elemento removido: %d\n", chave);
				return NULL;
			}else{
				//remover nós que possuem 2 filhos
				if(raiz->esquerda != NULL && raiz->direita != NULL){
					NoArv *aux = raiz->esquerda;
					while(aux->direita != NULL)
						aux = aux->direita;
					raiz->valor = aux->valor;
					//aux->valor = chave;
					printf(" Elemento trocado: %d\n", chave);
					raiz->esquerda = remover(raiz->esquerda, aux->valor);
					printf(" Elemento trocado: %d\n", chave);
					return raiz;
				}else{
					//remover nós que possuem 1 filhos
					NoArv *aux;
					if(raiz->esquerda != NULL)
						aux = raiz->esquerda;
					else
						aux = raiz->direita;
					free(raiz);
					printf(" Elemento com 1 filho removido: %d\n", chave);
					return aux;
				}	
			}
		}else{
			if(chave < raiz->valor)
				raiz->esquerda = remover(raiz->esquerda, chave);
			else
				raiz->direita = remover(raiz->direita, chave);
			return raiz;
		}
	}
}













