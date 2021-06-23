#include "ex05.h"


void iniciaArvore(PtrArvore *node){
	*node = NULL;
}

void destroiArvore(PtrArvore *node){
	if((*node) != NULL) {
		destroiArvore(&(*node)->filhoEsquerda);
		destroiArvore(&(*node)->filhoDireita);
		
		free(*node);
		(*node) = NULL;
	}
}

bool insereItem(PtrArvore *node, int x){
	if ((*node) == NULL){
		(*node) = malloc(sizeof(struct NoArvore));
		(*node)->filhoDireita  = NULL;
		(*node)->filhoEsquerda = NULL;
		(*node)->elemento = x;
		return true;
	}
	
	if( (*node)->elemento == x )
		return false;
	
	if( (*node)->elemento > x ){
		return(insereItem(&(*node)->filhoEsquerda, x));
	}else{
		return(insereItem(&(*node)->filhoDireita, x));
	}
}

void EmOrdem(PtrArvore *node){
	if((*node) == NULL) return;
	
	EmOrdem(&(*node)->filhoEsquerda);
	
	printf("%i ", (*node)->elemento);
	EmOrdem(&(*node)->filhoDireita);
}

int maiorRecursivo(PtrArvore *arvore){
	if((*arvore)->filhoDireita == NULL) return (*arvore)->elemento;
	
	return maiorRecursivo(&(*arvore)->filhoDireita);
}

int menorRecursivo(PtrArvore *arvore){
	if((*arvore)->filhoEsquerda == NULL) return (*arvore)->elemento;
	
	return menorRecursivo(&(*arvore)->filhoEsquerda);
}

void ordenaVetorTree(int n, int* array){
	if (n == 0){
		printf("ERRO!\nVetor vazio.\nEncerrando Execucao.");
		exit(1);
	}
	printf("\nVetor\n");
	for(int i = 0; i < n; i++)
		printf("%i ",array[i]);
	
	printf("\n\nVetor Ordenado\n");
	
	PtrArvore ordem;
	iniciaArvore(&ordem);
	
	for(int i = 0; i < n; i++)
		insereItem(&ordem, array[i]);
	
	EmOrdem(&ordem);
	
	printf("\nMaior Elemento: %i\n", maiorRecursivo(&ordem));
	printf("\nMenor Elemento: %i\n", menorRecursivo(&ordem));
	
	destroiArvore(&ordem);
}

int main() {
	int vetor[] = {25, 7, 10, 13, 33, 45, 11, 60, 5};
	int n = sizeof(vetor) / sizeof(int);
	ordenaVetorTree(n, vetor);
	
	printf("\n\n");
	
	int vetor2[] = {};
	int n2 = sizeof(vetor2) / sizeof(int);
	ordenaVetorTree(n2, vetor2);
	
	return 0;
}
