#include <stdio.h>
#include "data.h"

void imprimirData(Data d){
	printf("%d/%d/%d", d.dia,d.mes,d.ano);
}

Data lerData(){
	Data d;
	printf("\n Digite a data no formato dd mm aaaa: ");
	scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
	getchar();
	return d;
}
