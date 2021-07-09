#include "qsortHeader.h"

int comparaTempo(const void *a, const void *b){
	if((*(Atleta*)a).tempo == (*(Atleta*)b).tempo)
		return 0;
	
	if((*(Atleta*)a).tempo < (*(Atleta*)b).tempo)
		return -1;
	
	return 1;
}

int comparaNome(const void *a, const void *b){
	int comp = strcmp((*(Atleta*)a).nome,
					  (*(Atleta*)b).nome);
	
	if(comp == 0)
		return 0;
	
	if(comp<0)
		return -1;
	
	return 1;
}

void imprimeAtleta(int i, Atleta corredor, FILE *arq){
	printf("Atleta %i:\n",i+1);
	printf("Nome: %s\n", corredor.nome);
	printf("Pais: %s\n", corredor.pais);
	printf("Idade: %i\n", corredor.idade);
	printf("Altura (cm): %i\n", corredor.altura);
	printf("Tempo (s): %f\n", corredor.tempo);
	printf("======================\n");
	if(arq)
		fprintf(arq,"%s;%s;%i;%i;%f\n",
				corredor.nome,
				corredor.pais,
				corredor.idade,
				corredor.altura,
				corredor.tempo);
}

int main() {
	
	FILE *arq;
	arq = fopen("D:\\mathe\\Documents\\GITHUB\\EstruturaDados\\EstruturaDados2\\exercicios\\qsort\\atletas.txt", "r");
	if(!arq){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	
	Atleta atletas[8];
	
	for(int i = 0; i < 8; i++){
		fscanf(arq, "%[^;] ; %[^;] ; %i ; %i ; %f\n",
			   atletas[i].nome,
			   atletas[i].pais,
			   &atletas[i].idade,
			   &atletas[i].altura,
			   &atletas[i].tempo);
		
		imprimeAtleta(i, atletas[i], NULL);
	}
	
	fclose(arq);
	
	qsort(atletas, 8, sizeof (Atleta), comparaTempo);
	
	arq = fopen("D:\\mathe\\Documents\\GITHUB\\EstruturaDados\\EstruturaDados2\\exercicios\\qsort\\atletas_tempo.txt", "w");
	if(!arq){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	
	printf("\nAtletas ordenados por tempo\n");
	for(int i = 0; i < 8; i++)
		imprimeAtleta(i,atletas[i], arq);
	
	fclose(arq);
	
	arq = fopen("D:\\mathe\\Documents\\GITHUB\\EstruturaDados\\EstruturaDados2\\exercicios\\qsort\\atletas_nome.txt", "w");
	if(!arq){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	
	qsort(atletas, 8, sizeof (Atleta), comparaNome);
	printf("\nAtletas ordenados por nome\n");
	for(int i = 0; i < 8; i++)
		imprimeAtleta(i,atletas[i], arq);
	
	fclose(arq);
	
	return 0;
}
