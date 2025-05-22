#include <stdio.h>
#include "contrato.h"

void imprimirContrato(Contrato c){
	printf("\n\n\t\tDados do contrato\n");
	printf("\n Contrato: %d",c.codigo);
	printf("\n Cargo: %s",c.cargo);
	printf("\n Salario R$: %.2f",c.salario);
	printf("\n Data de admissao: ");
	imprimirData(c.dataAss);
}

Contrato lerContrato(){
	Contrato c;
	printf("\n--------------------------------------------------");
	printf("\n Codigo do contrato: ");
	scanf("%d", &c.codigo);
	printf(" Data de assinatura: ");
	c.dataAss = lerData();
	printf(" Cargo: ");
	fgets(c.cargo, 49, stdin);
	printf(" Salario: R$");
	scanf("%f", &c.salario);
	getchar();
	return c;
}


