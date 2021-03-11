#include "ex06.h"

const char* define_valor(int i){
	if(i==53 || i==52)
		return "C";
	else if(i%13==0)
		return "A";
	else if(i%13==1)
		return "2";
	else if(i%13==2)
		return "3";
	else if(i%13==3)
		return "4";
	else if(i%13==4)
		return "5";
	else if(i%13==5)
		return "6";
	else if(i%13==6)
		return "7";
	else if(i%13==7)
		return "8";
	else if(i%13==8)
		return "9";
	else if(i%13==9)
		return "10";
	else if(i%13==10)
		return "J";
	else if(i%13==11)
		return "Q";
	else if(i%13==12)
		return "K";
}

void criar_baralho(Baralho *novo){
	int i;
	for(i=0;i<54;i++){
		const char* valor = define_valor(i);
		strcpy(novo->cartas[i].valor, valor);
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
		imprimir_carta(&novo->cartas[i]);
	}
}

void imprimir_carta(Carta *carta){
	printf("Valor: %s\n", carta->valor);
	printf("Naipe: %c\n", carta->naipe );
	printf("Foi Jogada?: ");
	if(carta->foiJogada==1)
		printf("Sim\n");
	else
		printf("Nao\n");
	
	printf("\n");
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
	return cont;
}

Carta* topo(Baralho *novo){
	for(int i=53; i>=0; i--){
		if(novo->cartas[i].foiJogada==0){
			return &novo->cartas[i];
		}
	}
	printf("\nNão tem carta no baralho\n");
	return NULL;
}

Carta* fundo(Baralho *novo){
	for(int i=0; i<54; i++){
		if(novo->cartas[i].foiJogada==0){
			return &novo->cartas[i];
		}
	}
	printf("\nNão tem carta no baralho\n");
	return NULL;
}

Carta* carteado(Baralho *novo){
	srand(time(NULL));
	int posicao;
	
	do{
		posicao = rand()%54;
		
		if (novo->cartas[posicao].foiJogada==0) {
			novo->cartas[posicao].foiJogada = 1;
			return &novo->cartas[posicao];
		}
		
	} while (novo->cartas[posicao].foiJogada==1);
}

int main()
{
	
	Baralho novo;
	criar_baralho(&novo);
	
	// // Testar funções automaticamente
	
	printf("Baralho zerado:\n");
	imprimir_baralho(&novo);

	printf("\nBaralho embaralhado:\n");
	embaralhar(&novo);
	imprimir_baralho(&novo);

	printf("\nCartas nao jogadas: %i\n", cartasNaoJogadas(&novo));

	printf("\nCarta no Topo:\n");
	Carta* noTopo = topo(&novo);
	imprimir_carta(noTopo);

	printf("\n");

	printf("\nCarta no Fundo:\n");
	Carta* noFundo = fundo(&novo);
	imprimir_carta(noFundo);

	printf("\nCarteado:\n");
	for (int i = 1; i <= 3; ++i) {
		printf("Carta [%i]:\n", i);
		Carta* cartaAleatoria = carteado(&novo);
		imprimir_carta(cartaAleatoria);
	}

	printf("\nCartas nao jogadas: %i\n", cartasNaoJogadas(&novo));
	
	
	// // Interface para manipular as funções
	/*
	int op;
	Carta *c;
	do{
		printf("1 - Imprime Baralho\n");
		printf("2 - Embaralhar\n");
		printf("3 - Cartas não jogadas\n");
		printf("4 - Carta do Topo\n");
		printf("5 - Carta do Fundo\n");
		printf("6 - Carteado\n");
		printf("7 - Reiniciar\n");
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
			case 3:
				printf("\nAinda tem %i cartas no Baralho\n",cartasNaoJogadas(&novo));
				break;
			case 4:
				c = topo(&novo);
				imprimir_carta(c);
				break;
			case 5:
				c = fundo(&novo);
				imprimir_carta(c);
				break;
			case 6:
				printf("\nCarteado:\n");
				for (int i = 1; i <= 3; ++i) {
					printf("Carta [%i]:\n", i);
					Carta* cartaAleatoria = carteado(&novo);
					imprimir_carta(cartaAleatoria);
				}
				break;
			case 7:
				printf("Reiniciando baralho...\n");
				criar_baralho(&novo);
				break;
			case 0:
				printf("\nFinalizando\n");
				break;
			default:
				printf("\nOpcao Invalida\n");
		}

		printf("\nPressione qualquer tecla para continuar\n");
		getchar();

	}while (op!=0);
	*/
	
	return 0;
}
