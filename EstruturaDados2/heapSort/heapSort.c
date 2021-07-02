#include "heapSort.h"

void imprimirVetor(int *v, int inicio, int fim){
	printf("[ ");
	for(int i = inicio; i <= fim; i++){
		printf("%i, ",v[i]);
	}
	printf("]\t");
}

void criaHeap(int *v, int pai, int fim){
	int aux = v[pai];
	int filho = pai*2 + 1;
	
	while(filho <= fim){
		if(filho < fim && v[filho] < v[filho+1])
			filho++;
		
		if(aux < v[filho]){
			v[pai] = v[filho];
			pai = filho;
			filho = pai*2 + 1;
		}else
			filho = fim +1;
	}
	v[pai] = aux;
}

void heapSort(int *v, int n){
	int aux;
	for(int i = (n-1)/2; i >= 0; i--){
		criaHeap(v, i, n-1);
	}
	
	for(int i = n-1; i >= 1; i--){
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
		criaHeap(v, 0 , i-1);
	}
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
	heapSort(v, n);
	
	printf("\n\nOrdenado:\n");
	imprimirVetor(v, 0, n-1);
	
	return 0;
}
