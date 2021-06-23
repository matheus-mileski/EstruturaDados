#ifndef ESTRUTURADADOS_EX05_H
#define ESTRUTURADADOS_EX05_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura Arvore Binaria
typedef struct NoArvore *PtrArvore;

typedef struct NoArvore {
	int elemento;
	PtrArvore filhoEsquerda;
	PtrArvore filhoDireita;
} NoArvore;

void iniciaArvore(PtrArvore *node);
void destroiArvore(PtrArvore *node);
void EmOrdem(PtrArvore *node);
bool insereItem(PtrArvore *node, int x);

int maiorRecursivo(PtrArvore *arvore);
int menorRecursivo(PtrArvore *arvore);

void ordenaVetorTree(int n, int* array);

#endif //ESTRUTURADADOS_EX05_H
