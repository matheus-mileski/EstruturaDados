#include "ex04.h"

void trocaFilas(Fila *f1, Fila *f2){
	
	// cria fila auxiliar para receber f1
	Fila aux;
	iniciaFila(&aux);
	Objeto x;
	
	// insere os elementos de f1 em aux, até f1 estar vazia
	while(!estaVazia(f1)){
		x = desenfileira(f1);
		enfileira(x, aux);
	}
	
	// insere os elementos de f2 em f1, até f2 estar vazia
	while(!estaVazia(f2)){
		x = desenfileira(f2);
		enfileira(x, f1);
	}
	
	// insere os elementos de aux em f2, até aux estar vazia
	while(!estaVazia(aux)){
		x = desenfileira(aux);
		enfileira(x, f2);
	}
	
}

Lista* constroi(int n, int* v){

	Lista* l_encadeada;
	iniciaLista(l_encadeada);
	
	if(n == 0){
		printf("Vetor com zero elementos\n");
		return l_encadeada;
	}
	
	for(int i = 0; i <= n; i++){
		inserir(l_encadeada, v[i]);
	}
	return l_encadeada;
}

void inserirIntermediario(PilhaIntermediaria *p, Carta c){
	
	//se for o Rei a pilha tem q estar vazia
	if (c.carta == 13){
		if(estaVaziaInt(p)){
			empilhaInt(c, p);
		}else{
			printf("Impossivel inserir carta na pilha\n");
		}
	} else{
		//verifica se a carta inserida é igual a carta do topo - 1
		//e se as cores são diferentes
		if(c.carta == p->topo->c.carta - 1 && c.cor != p->topo->c.cor){
			empilhaInt(c, p);
		}else{
			printf("Impossivel inserir carta na pilha\n");
		}
	}
}

void inserirDefinitiva(PilhaDefinitiva *p, Carta c){
	
	// se for Ás verifica se está vazia
	if (c.carta == 1){
		if(estaVaziaDef(p)){
			empilhaDef(c, p);
		}else{
			printf("Impossivel inserir carta na pilha\n");
		}
	}else{
		//verifica se a carta inserida é igual a carta do topo + 1
		//e se os naipes são iguais
		if(c.carta == p->array[p->topo].carta + 1 && c.naipe == p->array[p->topo].naipe){
			empilhaInt(c, p);
		}else{
			printf("Impossivel inserir carta na pilha\n");
		}
	}
}

int main() {
	
	
	return 0;
}
