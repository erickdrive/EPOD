#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

PontoColeta* criar_ponto(int codigo, char* nome, char* tipo_material) {
    PontoColeta* novo = malloc(sizeof(PontoColeta));
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    strcpy(novo->tipo_material, tipo_material);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

//--------------------------------------------------------------------------------------

PontoColeta* inserir(PontoColeta* raiz, int codigo, char* nome, char* tipo_material) {
    if (raiz == NULL) {
        return criar_ponto(codigo, nome, tipo_material);
    } else if (codigo < raiz->codigo) {
        raiz->esquerda = inserir(raiz->esquerda, codigo, nome, tipo_material);
    } else if (codigo > raiz->codigo) {
        raiz->direita = inserir(raiz->direita, codigo, nome, tipo_material);
    } else {
        printf("Codigo ja existente: %d\n", codigo);
    }
    return raiz;
}

//--------------------------------------------------------------------------------------

PontoColeta* buscar(PontoColeta* raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo)
        return raiz;
    if (codigo < raiz->codigo)
        return buscar(raiz->esquerda, codigo);
    else
        return buscar(raiz->direita, codigo);
}

//-------------------------------------------------------------------------------------
void imprimir_em_ordem(PontoColeta* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esquerda);
        printf(" Codigo: %d\n Nome: %s\n Tipo de Material: %s\n\n", raiz->codigo, raiz->nome, raiz->tipo_material);
        imprimir_em_ordem(raiz->direita);
    }
}

//------------------------------------------------------------------------------------
