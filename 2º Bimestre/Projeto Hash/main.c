#include <stdio.h>
#include "hash.h"

#define TAM 15


int main() {
	
	int opcao, valor, retorno;
	Pessoa *buscar, tabela[TAM];
	
	inicializarTabela(tabela, TAM);
	
	do{
		printf("\n 0 - Sair\n 1 - Inserir\n 2 - Buscar\n 3 - Imprimir\n");
		printf(" Escolha uma Opcao:");
		scanf("%d", &opcao);
		getchar();
	
		switch(opcao){
			case 1:
				inserir(tabela, TAM);
				break;
			case 2:
				printf("\nCPF: ");
				scanf("%d", &valor);
				buscar = busca(tabela, valor, TAM);
				if(buscar){
					printf("\nCPF encontrado\n");
					imprimirPessoa(*buscar);
				}
				else	
					printf("\nCPF não encontrado");
				break;
			case 3:
				imprimir(tabela, TAM);
				break;
			default:
				printf("\nOpcao invalida.\n");
		}	
	}while(opcao != 0);
}
