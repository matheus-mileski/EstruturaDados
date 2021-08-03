#include "cadastroIndexado.h"

/*
 *  3 # 30 # 2 # 25 \n Total 64
 *  246 Henrique Cardoso               25 Boxe
 *	070 Rafael Golias                  31 Boxe
 *	109 Gabriel Alves                  27 Basquete
 *  ...
 */

/*
 * Índice Primário: struct ->  RRN,id
 *                  no arquivo 001#246\n
 *
 * Índices Secundários:
 * - Nome (fortemente ligado):
 */

int comparaId(const void *a, const void *b){
	if((*(IndiceP *)a).id == (*(IndiceP *)b).id)
		return 0;
	
	if((*(IndiceP *)a).id < (*(IndiceP*)b).id)
		return -1;
	
	return 1;
}

void criaIndicePrimario(){
	printf("Criando Indice Primario...\n");
	
	FILE *entrada;
	
	entrada = fopen("atletas.txt", "r");
	
	if(entrada == NULL){
		printf("\nERRO!\nArquivo de entrada nao pode ser aberto.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	int i = 0;
	IndiceP indice[200];
	
	while(1){
		indice[i].rrn = i;
		
		// utilizando delimitador de tamanho de scanf e * para ignorar tudo até encontrar o \n
		fscanf(entrada, "%3d %*[^\n]\n", &indice[i].id);

		if(feof(entrada))
			break;
		else
			i++;
	}
	fclose(entrada);
	
	qsort(indice, 200, sizeof (IndiceP), comparaId);
	
	FILE *saida;
	
	saida = fopen("indicePrimario.txt", "w");
	
	if(saida == NULL){
		printf("\nERRO!\nArquivo de entrada nao pode ser aberto.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	for (int j = 0; j < 200; j++)
		fprintf(saida, "%03d %03d\n",indice[j].id, indice[j].rrn);
	
	fclose(saida);
	
}

void criaIndiceNome(){

}

void criaIndiceModalidade(){

}

int main() {
	
	// se os indices não existirem, chama a função para criar
	if( access( "indicePrimario.txt", F_OK ) != 0)
		criaIndicePrimario();
	
	// if( access( "indiceNome.txt", F_OK ) != 0)
	// 	criaIndiceNome();
	//
	// if( access( "indiceModalidade.txt", F_OK ) != 0)
	// 	criaIndiceModalidade();
	
	// TODO: talvez seja possível unificar as funções para criar índice secundário
	
	
	
	
	return 0;
}
