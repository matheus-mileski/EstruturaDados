#include "bubbleSort.h"

/**
* \brief Ordena o vetor usando BubbleSort
*
* \param v vetor a ser ordenado
* \param n tamanho do vetor
*
* Ordena o vetor usando o método BubbleSort
* Esse algoritmo tem um comportamento assintótico O(N²)
*/

void imprimirVetor(int *v, int n){
	for(int i = 0; i < n; i++){
		printf("%i, ",v[i]);
	}
	printf("\n");
}

void bubbleSort(int *v, int n){
	int troca = 0;
	int fim = n-1;
	int aux;
	
	do{
		troca = 0;
		for(int i = 0; i < fim; i++){
			if(v[i] > v[i+1]){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				troca = 1;
				imprimirVetor(v, n);
			}
		}
		fim--;
	}while(troca != 0);
	
}

int main() {
	
	int v[] = {7,6,5,8,9,0,1,3,2,4};
	int n = 10;
	
	printf("Sem Ordenar:\n");
	imprimirVetor(v,n);
	
	printf("\nOrdenando:\n");
	bubbleSort(v, n);
	
	printf("\nOrdenado:\n");
	imprimirVetor(v, n);
	
	return 0;
}
