#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void) {
    NoArv *raiz = NULL, *busca;
    int opcao, valor;
    
    do{
    	printf("\n 0 - Sair");
    	printf("\n 1 - Inserir");
    	printf("\n 2 - Imprimir");
    	printf("\n 3 - Buscar");
    	printf("\n 4 - Altura");
    	printf("\n 5 - Tamanho");
    	printf("\n 6 - Folhas");
    	printf("\n 7 - Remover");
    	printf("\n Escolha uma Opcao: ");
    	scanf("%d", &opcao);
    	
    	switch(opcao){
    		case 1:
    		printf("\n valor: ");
			scanf("%d",&valor);
			inserir_v3(&raiz,valor);
			break;	
    		case 2:
    			printf("\n Pre-ordem: ");
    			imprimir_pre_ordem(raiz);
    			printf("\n Ordem: ");
    			imprimir_in_ordem(raiz);
    		    printf("\n Pos-Ordem: ");
    			imprimir_pos_ordem(raiz);
    			break;
    		case 3:
    			printf("\nValor (busca): ");
    			scanf("%d", &valor);
    		    busca = buscar_v2(raiz, valor);
    		    if(busca)
    		     printf("\n Valor encontrado: %d\n", busca->valor);
    		    else
    		      printf("\n Valor não encontrado");
    		    break;
    		case 4:
    			printf("\n Altura: %d", altura(raiz));
    			break;
    		case 5: 
    		    printf("\n Quantidade de nos: %d", quantidade_nos(raiz));
    		    break;
    		case 6:
    			printf("\n Quantidade de folhas: %d", quantidade_folhas(raiz));
    			break;
    		case 7:
    			printf("\n Remover valor: ");
    			scanf("%d", &valor);
    			raiz = remover(raiz, valor);
    			break;
    		default:
    			if(opcao != 0)
    			printf("opcao invalida");
		}
		
	}while(opcao != 0);
}
