#include <stdio.h>
#include "pessoa.h"

void imprimirPessoa(Pessoa p){
	printf("\n\t\tDados da Pessoa");
	printf("\n Nome: %s", p.nome);
	printf(" CPF: %d", p.cpf);
	printf("\n Data de nascimento: ");
	imprimirData(p.dataNas);
	imprimirEndereco(p.end);
	imprimirContrato(p.contr);	
}

Pessoa lerPessoa(){
	Pessoa p;
	printf("\n Nome: ");
	fgets(p.nome, 49, stdin);
	printf(" CPF: ");
	scanf("%d", &p.cpf);
	printf(" Data de nascimento: ");
	p.dataNas = lerData();
	p.contr = lerContrato();
	p.end = lerEndereco();
	getchar();
	return p;
}
