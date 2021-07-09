#include "qsortHeader.h"

void limpa_buffer(){
	char buffer[101];
	do {
		fgets(buffer, sizeof buffer, stdin);
	} while (buffer[strlen(buffer) - 1] != '\n');
}

int main() {
	
	FILE *arq;
	arq = fopen("atletas.txt", "w");
	if(!arq){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	
	Atleta atletas[8];
	
	printf("Informacoes dos Atletas\n");
	for(int i = 0; i < 8; i++){
		printf("Atleta %i:\n",i+1);
		printf(" Nome: ");
		fgets(atletas[i].nome, 24, stdin);
		atletas[i].nome[strlen(atletas[i].nome)-1] = '\0';
		printf("Pais: ");
		fgets(atletas[i].pais, 24, stdin);
		atletas[i].pais[strlen(atletas[i].pais)-1] = '\0';
		printf("Idade: ");
		scanf("%i", &atletas[i].idade);
		limpa_buffer();
		printf("Altura (cm): ");
		scanf("%i", &atletas[i].altura);
		limpa_buffer();
		printf("Tempo (s): ");
		scanf("%f", &atletas[i].tempo);
		limpa_buffer();
		printf("======================\n");
	}
	
	for(int i = 0; i < 8; i++) {
		printf("Atleta %i:\n",i+1);
		printf("Nome: %s\n", atletas[i].nome);
		printf("Pais: %s\n", atletas[i].pais);
		printf("Idade: %i\n", atletas[i].idade);
		printf("Altura (cm): %i\n", atletas[i].altura);
		printf("Tempo (s): %f\n", atletas[i].tempo);
		printf("======================\n");
		fprintf(arq,"%s;%s;%i;%i;%f\n",
				atletas[i].nome,
				atletas[i].pais,
				atletas[i].idade,
				atletas[i].altura,
				atletas[i].tempo);
	}
	
	fclose(arq);
	
	return 0;
}
