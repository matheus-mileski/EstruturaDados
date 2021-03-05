#include "ex06.h"

const char* define_valor(int i){
	char *valor[3];
	if(i==53 || i==52)
		strcpy(*valor,"C");
	else if(i%13==0)
		strcpy(*valor,"A");
	else if(i%13==1)
		strcpy(*valor,"2");
	else if(i%13==2)
		strcpy(*valor,"3");
	else if(i%13==3)
		strcpy(*valor,"4");
	else if(i%13==4)
		strcpy(*valor,"5");
	else if(i%13==5)
		strcpy(*valor,"6");
	else if(i%13==6)
		strcpy(*valor,"7");
	else if(i%13==7)
		strcpy(*valor,"8");
	else if(i%13==8)
		strcpy(*valor,"9");
	else if(i%13==9)
		strcpy(*valor,"10");
	else if(i%13==10)
		strcpy(*valor,"J");
	else if(i%13==11)
		strcpy(*valor,"Q");
	else if(i%13==12)
		strcpy(*valor,"K");
	
	return *valor;
}

void criar_baralho(Baralho *novo){
	int i;
	for(i=0;i<54;i++){
		strcpy(novo->cartas[i].valor,define_valor(i));
		novo->cartas[i].foiJogada=0;
		if(i<13)
			novo->cartas[i].naipe='C';
		else if(i<26)
			novo->cartas[i].naipe='E';
		else if(i<39)
			novo->cartas[i].naipe='O';
		else if(i<52)
			novo->cartas[i].naipe='P';
		else{
			novo->cartas[i].naipe='J';
		}
	}
}

void imprimir_baralho(Baralho *novo){
	
	for(int i=0;i<54;i++){
		printf("Carta [%i]\n",i+1 );
		printf("Valor: %s\n",novo->cartas[i].valor);
		printf("Naipe: %c\n",novo->cartas[i].naipe );
		printf("Foi Jogada?: ");
		//if(novo->cartas[i].foiJogada==true)
		if(novo->cartas[i].foiJogada==1)
			printf("Sim\n");
		else
			printf("Nao\n");
		
		printf("\n");
	}
}

void embaralhar(Baralho *novo){
	srand(time(NULL));
	int posicao;
	Carta carta_troca;
	for(int i=0;i<54;i++){
		posicao = rand()%54;
		strcpy(carta_troca.valor,novo->cartas[i].valor);
		carta_troca.naipe = novo->cartas[i].naipe;
		strcpy(novo->cartas[i].valor,novo->cartas[posicao].valor);
		novo->cartas[i].naipe = novo->cartas[posicao].naipe;
		strcpy(novo->cartas[posicao].valor,carta_troca.valor);
		novo->cartas[posicao].naipe = carta_troca.naipe;
		novo->cartas[i].foiJogada=0;
		novo->cartas[posicao].foiJogada=0;
	}
}

int cartasNaoJogadas(Baralho *novo){
	
	int cont=0;
	for(int i=0;i<54;i++){
		if(novo->cartas[i].foiJogada==0)
			cont++;
	}
	
}

int main()
{
	Baralho novo;
	int op;
	criar_baralho(&novo);
	
	do{
		//system("clear");
		printf("1 - Imprime Baralho\n");
		printf("2 - Embaralhar\n");
		printf("3 - Cartas não jogadas\n");
		printf("4 - Carta do Topo\n");
		printf("5 - Carta do Fundo\n");
		printf("6 - Carteado\n");
		printf("0 - Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%i",&op );
		getchar();
		printf("\n\n");
		switch (op) {
			case 1:
				imprimir_baralho(&novo);
				break;
			case 2:
				embaralhar(&novo);
				break;
				/*case 3:
					printf("\nAinda tem %i cartas no Baralho\n",cartasNaoJogadas(&novo));
					break;
				case 4:
					topo(&novo);
					break;
				case 5:
					fundo(&novo);
					break;
				case 6:
					carteado(&novo);
					break;*/
			case 0:
				printf("\nFinalizando\n");
				break;
			default:
				printf("\nOpcao Invalida\n");
		}
		
		printf("\nPressione qualquer tecla para continuar\n");
		getchar();
		
	}while (op!=0);
	
	return 0;
}
