#include "ex05.h"

void preencher_bandas(Obj bandas[5]){
	
	for(int i=0;i<5;i++){
		printf("Banda %i\n",i+1 );
		printf("Nome:");
		scanf("%[^\n]",bandas[i].nome);
		getchar();
		printf("Estilo:");
		scanf("%[^\n]",bandas[i].estilo);
		getchar();
		printf("Numero de integrantes:");
		scanf("%i",&bandas[i].n_integrantes);
		getchar();
		printf("Posicao no Ranking:");
		scanf("%i",&bandas[i].posicao_raking);
		getchar();
	}
}

void exibir_bandas(Obj bandas[5]){
	
	for(int i=0;i<5;i++){
		printf("Banda %i\n",i+1 );
		printf("Nome: %s\n",bandas[i].nome );
		printf("Estilo: %s\n", bandas[i].estilo);
		printf("Numero de Integrantes: %i\n",bandas[i].n_integrantes );
		printf("Posicao no Ranking: %i\n",bandas[i].posicao_raking );
		printf("\n\n");
	}
	
}

void exibir_ranking(Obj bandas[5]){
	
	int op;
	
	printf("Informe a posicao a ser exibida: ");
	scanf("%i",&op);
	getchar();
	
	for(int i=0;i<5;i++){
		if(op == bandas[i].posicao_raking){
			printf("Banda %i\n",i+1 );
			printf("Nome: %s\n",bandas[i].nome );
			printf("Estilo: %s\n", bandas[i].estilo);
			printf("Numero de Integrantes: %i\n",bandas[i].n_integrantes );
			printf("Posicao no Ranking: %i\n",bandas[i].posicao_raking );
			printf("\n\n");
		}
	}
}

int main() {
	Obj bandas[5];
	int op;
	
	preencher_bandas(bandas);
	
	getchar();
	printf("Pressione qualquer tecla para contnuar\n");
	getchar();
	printf("\n");
	
	do{
		printf("1 - Exibir todas as bandas\n");
		printf("2 - Exibir posicao no Ranking\n");
		printf("0 - Sair\n");
		printf("Escolha uma das opcoes acima:");
		scanf("%i",&op );
		getchar();
		
		switch (op) {
			case 1:
				exibir_bandas(bandas);
				break;
			case 2:
				exibir_ranking(bandas);
				break;
			case 0:
				printf("\nFinalizando programa\n");
				break;
			default:
				printf("Opcao invalida\n");
		}
		getchar();
		printf("Pressione qualquer tecla para contnuar\n");
		getchar();
		printf("\n");
		
	}while (op!=0);
	
	
	return 0;
}
