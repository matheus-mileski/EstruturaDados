#include "insertionSort.h"

/**
* \brief Ordena o vetor usando InsertionSort
*
* \param v vetor a ser ordenado
* \param n tamanho do vetor
*
* Ordena o vetor usando o método InsertionSort
* Esse algoritmo tem um comportamento assintótico O(n²)
*/

void imprimirVetor(int *v, int n){
	for(int i = 0; i < n; i++){
		printf("%i, ",v[i]);
	}
	printf("\n");
}

void insertionSort(int *v, int n){
	// cria as variáveis auxiliares
	int eleito, j;
	
	// loop para percorrer o vetor da posição 1 até o final
	for(int i = 1; i < n; i++){
		// define o valor analisado
		eleito = v[i];
		
		// loop que percorre do valor analisado até a posição 0, voltando
		// para quando chegar a posição 0 ou quando o valor eleito for maior
		// ou igual ao valor na posição j
		for (j = i-1; (j >= 0) && (eleito < v[j]) ; j--) {
			// avança os valores em uma posição
			v[j+1] = v[j];
		}
		// ao final, insere o valor analisado (eleito) na posição correta
		v[j+1] = eleito;
		imprimirVetor(v, n);
	}
}

int main() {
	int v[] = {7,6,5,8,9,0,1,3,2,4};
	int n = 10;
	
	printf("Sem Ordenar:\n");
	imprimirVetor(v,n);
	
	printf("\nOrdenando:\n");
	insertionSort(v, n);
	
	printf("\nOrdenado:\n");
	imprimirVetor(v, n);
	
	return 0;
}
