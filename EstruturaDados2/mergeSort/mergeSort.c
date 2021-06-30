#include "mergeSort.h"

void imprimirVetor(int *v, int inicio, int fim){
	printf("[ ");
	for(int i = inicio; i <= fim; i++){
		printf("%i, ",v[i]);
	}
	printf("]\t");
}

/**
* \brief Ordena o vetor usando MergeSort
*
* \param v vetor a ser ordenado
* \param inicio índice do início do vetor
* \param fim índice do final do vetor
*
* Ordena o vetor usando o método MergeSort
* Esse algoritmo tem um comportamento assintótico O(n log n)
*/

void mergeSort(int *v, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		
		imprimirVetor(v, inicio, meio);
		imprimirVetor(v, meio+1, fim);
		printf("\n");
		
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
		
		imprimirVetor(v, inicio, fim);
		printf("\n");
	}
}

/**
* \brief Intercala dois vetores
*
* \param v vetor a ser intercalado
* \param inicio índice do início do vetor
* \param meio índice do último elemento do primeiro vetor
* \param fim índice do final do segundo vetor
*
* Intercala um vetor dividido em duas partes de maneira
* ordenada
*/

void merge(int *v, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, j, k;
	tamanho = fim - inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int *)malloc(tamanho * sizeof(int));
	
	// imprimirVetor(v, p1, meio);
	// imprimirVetor(v, p2, fim);
	// printf("\n");
	
	if(temp != NULL){
		for(int i = 0; i < tamanho; i++){
			if(p1 <= meio && p2 <= fim){
				if(v[p1] < v[p2])
					temp[i] = v[p1++];
				else
					temp[i] = v[p2++];
			}else{
				if(p1 <= meio)
					temp[i] = v[p1++];
				else
					temp[i] = v[p2++];
			}
		}
		for(j = 0, k = inicio; j < tamanho; j++, k++ ){
			v[k] = temp[j];
		}
	}
	
	free(temp);
	
}

int main() {
	
	int v[] = {5, 7, 8, 6, 1, 2, 0, 9, 3, 4};
	int n = 10;
	
	printf("Sem Ordenar:\n");
	imprimirVetor(v,0, n-1);
	printf("\n");
	
	printf("\nOrdenando:\n");
	mergeSort(v, 0, n-1);
	
	printf("\nOrdenado:\n");
	imprimirVetor(v, 0, n-1);
	
	return 0;
}
