#include "quickSort.h"

void imprimirVetor(int *v, int inicio, int fim){
	printf("[ ");
	for(int i = inicio; i <= fim; i++){
		printf("%i, ",v[i]);
	}
	printf("]\t");
}

/**
* \brief Ordena o vetor usando QuickSort
*
* \param v vetor a ser ordenado
* \param inicio índice do início do vetor
* \param fim índice do final do vetor
*
* Ordena o vetor usando o método QuickSort
* Esse algoritmo tem um comportamento assintótico O(n log n)
*/

void quickSort(int *v, int inicio, int fim){
	bool alt = false;
	// bool alt = true;
	
	int pivo;
	if(inicio < fim){
		if(!alt)
			pivo = particiona(v, inicio, fim);
		else
			pivo = particionaAlt(v, inicio, fim);
		
		printf("\nPivo = %i\n",v[pivo]);
		imprimirVetor(v,inicio, pivo-1);
		imprimirVetor(v, pivo+1, fim);
		
		quickSort(v, inicio, pivo-1);
		quickSort(v, pivo+1, fim);
	}
}

/**
* \brief Particiona o vetor
*
* \param v vetor a ser particionado
* \param inicio índice do início do vetor
* \param fim índice do final do vetor
*
* \return pivo indice do pivo na posição correta
*
* Calcula o pivô e rearranja os dados em
* menores que o pivô a esquerda, maiores que
* o pivô a direita
*/

int particiona(int *v, int inicio, int fim){
	int esq = inicio;
	int dir = fim;
	int pivo = v[inicio];
	int aux;

	while(esq < dir){
		while(v[esq] <= pivo && esq <= fim){
			esq++;
		}
		while(v[dir] > pivo && dir >= 0){
			dir--;
		}
		if (esq < dir){
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

int particionaAlt(int *v, int inicio, int fim){
	int troca;
	int cont = inicio;

	for(int i = inicio+1; i <= fim; i++){
		if(v[i] < v[inicio]){
			cont++;
			troca = v[i];
			v[i] = v[cont];
			v[cont] = troca;
		}
	}
	troca = v[inicio];
	v[inicio] = v[cont];
	v[cont] = troca;
	
	return cont;
}

int main() {
	
	int n = 10;
	int *v = (int*)malloc(n * sizeof (int));
	
	srand(time(NULL));
	
	int intervalo = n*n;
	
	for(int i = 0; i < n; i++){
		// gerar um valor aleatorio de -(n*n) até (n*n)
		v[i] = (rand() % (intervalo*2)) - intervalo;
	}
	
	printf("Sem Ordenar:\n");
	imprimirVetor(v,0, n-1);
	printf("\n");
	
	printf("\nOrdenando:");
	quickSort(v, 0, n-1);
	
	printf("\n\nOrdenado:\n");
	imprimirVetor(v, 0, n-1);
	
	return 0;
}
