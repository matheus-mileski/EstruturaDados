#include "ex04.h"

void *criar_vetor(int tamanho){
	int *vet;
	
	vet = (int *)malloc(tamanho*sizeof(int));
	
	for(int i=0;i<tamanho;i++){
		printf("v[%i] =",i);
		scanf("%i",&vet[i]);
	}
	return vet;
}

int main() {
	
	int *vet,n;
	
	printf("Informe o tamanho do vetor:");
	scanf("%i",&n);
	
	vet = criar_vetor(n);
	
	printf("\n\nVetor: ");
	for(int i=0;i<n;i++){
		
		printf("%i\t",vet[i]);
	}
	
	free(vet);
	
	return 0;
}
