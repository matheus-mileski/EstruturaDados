

#ifndef ESTRUTURADADOS_EX05_H
#define ESTRUTURADADOS_EX05_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[50];
	char estilo[50];
	int n_integrantes;
	int posicao_raking;
}Obj;

void preencher_bandas(Obj bandas[5]);
void exibir_bandas(Obj bandas[5]);
void exibir_ranking(Obj bandas[5]);


#endif //ESTRUTURADADOS_EX05_H
