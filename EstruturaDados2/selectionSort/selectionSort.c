#include "selectionSort.h"

/**
* \brief Ordena o vetor usando SelectionSort
*
* \param v vetor a ser ordenado
* \param n tamanho do vetor
*
* Ordena o vetor usando o método SelectionSort
* Esse algoritmo tem um comportamento assintótico O(n²)
*/

void imprimirVetor(int *v, int n){
	for(int i = 0; i < n; i++){
		printf("%i, ",v[i]);
	}
	printf("\n");
}

void selectionSort(int *v, int n){
	// cria as variáveis auxiliares
	int menor, aux;
	
	// loop para percorrer o vetor até a penultima posição
	for(int i = 0; i < n-1; i++){
		// define que a posição analisada é a menor
		menor = i;
		
		// loop para percorrer o vetor a partir da posição analisada
		for (int j = i+1; j < n; j++) {
			// sempre que for encontrado um valor menor, salva o seu indice na variavel menor
			if(v[j] < v[menor])
				menor = j;
		}
		
		// se encontrar um valor menor que o valor da posição analisada, faz a troca
		if( i != menor){
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
		imprimirVetor(v, n);
	}
	
}

int main() {
	
	int v[] = {7,6,5,8,9,0,1,3,2,4};
	int n = 10;
	
	printf("Sem Ordenar:\n");
	imprimirVetor(v,n);
	
	printf("\nOrdenando:\n");
	selectionSort(v, n);
	
	printf("\nOrdenado:\n");
	imprimirVetor(v, n);
	
	return 0;
}
