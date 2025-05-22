#include<stdio.h>
#include "endereco.h"

void imprimirEndereco(Endereco end){
	printf("\n\n\t\tDados do endereco\n");
	printf("\n Rua: %s", end.rua);
	printf(" Numero: %d", end.num);
	printf("\n Bairro: %s", end.bairro);
	printf("\n Cidade: %s", end.cidade);
	printf("\n Pais: %s", end.pais);
	printf("\n CEP: %d", end.cep);
	
}

Endereco lerEndereco(){
	Endereco end;
	printf("\n--------------------------------------------------");
	printf("\n Rua: ");
	fgets(end.rua, 49, stdin);
	printf(" Numero: ");
	scanf("%d", &end.num);
	printf(" Bairro: ");
	scanf("%s",&end.bairro);
	printf(" CEP: ");
	scanf("%d", &end.cep);
	printf(" Cidade: ");
	scanf("%c");
	scanf("%s",&end.cidade);
	printf(" Pais: ");
	scanf("%s",&end.pais);
	
	return end;
}



