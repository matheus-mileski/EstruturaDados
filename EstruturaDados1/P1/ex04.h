#ifndef ESTRUTURADADOS_EX04_H
#define ESTRUTURADADOS_EX04_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int chave;
	/* outros componentes */
} Objeto;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
	Objeto obj;
	PtrNoFila proximo;
} NoFila;

typedef struct {
	PtrNoFila inicio;
	PtrNoFila fim;
	int tamanho;
} Fila;

void iniciaFila(Fila *fila);
void imprimeFila(Fila *fila);
void enfileira(Objeto x, Fila *fila);
void desenfileira(Fila *fila, Objeto *x);
//Objeto desenfileira(Fila *fila);
int estaVazia(Fila *fila);
int tamanhoFila(Fila *fila);
Objeto inicioFila(Fila *fila);
Objeto fimFila(Fila *fila);


typedef struct  {
	int chave;
} Objeto;

// tipo abstrato para as cartas
typedef struct  {
	int carta;
	char naipe;
	int cor;
} Carta;

// tipo abstrato tipo lista para o Baralho
typedef struct NoLista *PtrNoLista;
typedef struct NoLista {
	Carta c;
	PtrNoLista proximo;
} NoLista;
typedef struct {
	PtrNoLista primeiro;
	int tamanho;
} ListaBaralho;

// tipo abstrato tipo Pilha Dinâmica para as Pilhas Intermediárias
typedef struct NoPilha *PtrNoPilha;
typedef struct NoPilha{
	Carta c;
	PtrNoPilha proximo;
} NoPilha;
typedef struct {
	PtrNoPilha topo;
	int tamanho;
} PilhaIntermediaria;

// tipo abstrato tipo Pilha Estática para as Pilhas Definitivas
typedef struct {
	Carta array[13];
	int topo;
} PilhaDefinitiva;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
	Item elemento;
	PtrNoLista proximo;
} NoLista;

typedef struct {
	PtrNoLista primeiro;
	int tamanho;
} Lista;

void iniciaLista(Lista *list);
void inserir(Lista *list, int x);
void imprimirLista(Lista *list);
void destruirLista(Lista *list);
bool estaVazia(Lista *list);
bool pesquisar(Lista *list, int key);
int tamanhoLista(Lista *list);
void removeElemento(Lista *list, int chave, Objeto *item);
void removePrimeiro(Lista *list, Objeto *item);
void removeUltimo(Lista *list, Objeto *item);
Objeto primeiro(Lista *list);
Objeto ultimo(Lista *list);
void inserirDefinitiva(PilhaDefinitiva *p, Carta c);
bool estaVaziaInt(PilhaIntermediaria *pilha);
bool estaVaziaDef(PilhaDefinitiva *pilha);
void empilhaInt(Carta c, PilhaIntermediaria *pilha);
void empilhaDef(Carta c, PilhaDefinitiva *pilha);
#endif //ESTRUTURADADOS_EX04_H
