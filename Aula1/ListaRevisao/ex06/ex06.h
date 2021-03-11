#ifndef ESTRUTURADADOS_EX06_H
#define ESTRUTURADADOS_EX06_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	char valor[3];
	char naipe;
	int foiJogada;
}Carta;

typedef struct{
	Carta cartas[54];
}Baralho;

const char* define_valor(int i);
void criar_baralho(Baralho *novo);
void imprimir_baralho(Baralho *novo);
void imprimir_carta(Carta *carta);
void embaralhar(Baralho *novo);
int cartasNaoJogadas(Baralho *novo);
Carta* topo(Baralho *novo);
Carta* fundo(Baralho *novo);
Carta* carteado(Baralho *novo);


#endif //ESTRUTURADADOS_EX06_H
