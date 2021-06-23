#ifndef AT03_MANIPULACAO_ARVORES_INDICE_REMISSIVO_MATHEUS_MILESKI_ED20202_AT03_INDICEREMISSIVO_MATHEUSMILESKI_H
#define AT03_MANIPULACAO_ARVORES_INDICE_REMISSIVO_MATHEUS_MILESKI_ED20202_AT03_INDICEREMISSIVO_MATHEUSMILESKI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXTAM 1024

// Estrutura Fila Dinamica
typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
	int pagina;
	PtrNoFila proximo;
} NoFila;

typedef struct {
	PtrNoFila inicio;
	PtrNoFila fim;
	int tamanho;
} FilaDinamica;

// Estrutura Arvore Binaria
typedef struct{
	char termo[MAXTAM];
	FilaDinamica paginas;
} Objeto;

typedef struct NoArvore *PtrArvore;

typedef struct NoArvore {
	Objeto elemento;
	PtrArvore filhoEsquerda;
	PtrArvore filhoDireita;
} NoArvore;

// Funcoes Fila Dinamica
void iniciaFila(FilaDinamica *fila);
void imprimeFila(FilaDinamica *fila, FILE *saida);
void enfileira(int x, FilaDinamica *fila);
void desenfileira(FilaDinamica *fila);
bool estaVaziaFila(FilaDinamica *fila);

// Funcoes Arvore Binaria
void iniciaArvore(PtrArvore *node);
void destroiArvore(PtrArvore *node);
void EmOrdem(PtrArvore *node, FILE *saida);
bool insereItem(PtrArvore *node, Objeto x);
bool procuraItem(PtrArvore *node, char *palavra, int page);

bool checar_arquivo(char *arquivo);

#endif //AT03_MANIPULACAO_ARVORES_INDICE_REMISSIVO_MATHEUS_MILESKI_ED20202_AT03_INDICEREMISSIVO_MATHEUSMILESKI_H
