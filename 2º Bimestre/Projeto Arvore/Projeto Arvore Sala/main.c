#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void) {
    PontoColeta *raiz = NULL;
    int opcao, codigo;
    char nome[100], tipo_material[50];
    
    do{
    	printf("\n 0 - Sair");
        printf("\n 1 - Inserir ponto de coleta");
        printf("\n 2 - Buscar");
        printf("\n 3 - Imprimir pontos (ordem crescente de codigo)");
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);
    	
    switch(opcao) {
            case 1:
                printf("\n Codigo do ponto: ");
                scanf("%d", &codigo);
                getchar();
                printf(" Nome do ponto: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf(" Tipo de material: ");
                fgets(tipo_material, sizeof(tipo_material), stdin);
                tipo_material[strcspn(tipo_material, "\n")] = '\0';
                raiz = inserir(raiz, codigo, nome, tipo_material);
                break;

            case 2:
                printf(" Digite o codigo para busca: ");
                scanf("%d", &codigo);
                PontoColeta* encontrado = buscar(raiz, codigo);
                if (encontrado) {
                    printf("\n Ponto encontrado:\n");
                    printf(" Codigo: %d\n Nome: %s\n Tipo de Material: %s\n", encontrado->codigo, encontrado->nome, encontrado->tipo_material);
                } else {
                    printf(" Ponto nao encontrado.\n");
                }
                break;

            case 3:
                printf("\n\t\t\t Imprimindo Pontos de Coleta \n");
                imprimir_em_ordem(raiz);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção invalida.\n");
        }

    } while(opcao != 0);
}
