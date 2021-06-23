#include "ED20202-AT03-IndiceRemissivo-MatheusMileski.h"

bool checar_arquivo(char *arquivo) {
	
	if(arquivo[strlen(arquivo)-4] == '.'){
		if(arquivo[strlen(arquivo)-3] == 't'){
			if(arquivo[strlen(arquivo)-2] == 'x'){
				if(arquivo[strlen(arquivo)-1] == 't'){
					return true;
				}
			}
		}
	}
	return false;
}

void iniciaFila(FilaDinamica *fila){
	fila->inicio = NULL;
	fila->fim = NULL;
	fila->tamanho = 0;
}

bool estaVaziaFila(FilaDinamica *fila){
	return (fila->tamanho == 0);
}

void enfileira(int x, FilaDinamica *fila){
	// verifica se essa pagina ja foi inserida pra essa palavra
	if(!estaVaziaFila(fila)) {
		if (fila->fim->pagina == x)
			return;
	}
	
	PtrNoFila aux;
	aux = (PtrNoFila)malloc(sizeof(PtrNoFila));
	aux->pagina = x;
	if(estaVaziaFila(fila)){
		fila->inicio = aux;
		fila->fim = aux;
		aux->proximo = NULL;
	}else{
		aux->proximo = NULL;
		fila->fim->proximo = aux;
		fila->fim = aux;
	}
	fila->tamanho++;
}

void desenfileira(FilaDinamica *fila){
	if(!estaVaziaFila(fila)){
		PtrNoFila aux;
		aux = fila->inicio;
		fila->inicio = fila->inicio->proximo;
		free(aux);
		fila->tamanho--;
	}
}

void imprimeFila(FilaDinamica *fila, FILE *saida){
	PtrNoFila aux;
	
	for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
		printf("%d", aux->pagina);
		fprintf(saida, "%d", aux->pagina);
		if(aux->proximo != NULL) {
			printf(",");
			fprintf(saida, ",");
		}
	}
	printf("\n");
	fprintf(saida, "\n");
}

void iniciaArvore(PtrArvore *node){
	*node = NULL;
}

bool estaVaziaArvore(PtrArvore *node) {
	return(*node == NULL);
}

void destroiArvore(PtrArvore *node){
	if((*node) != NULL) {
		destroiArvore(&(*node)->filhoEsquerda);
		destroiArvore(&(*node)->filhoDireita);
		while((*node)->elemento.paginas.inicio != NULL){
			desenfileira(&(*node)->elemento.paginas);
		}
		// if (estaVaziaFila(&(*node)->elemento.paginas))
		// 	printf("Fila destruida\n");
		free(*node);
		(*node) = NULL;
	}
}

bool insereItem(PtrArvore *node, Objeto x){
	if ((*node) == NULL){
		(*node) = malloc(sizeof(struct NoArvore));
		(*node)->filhoDireita  = NULL;
		(*node)->filhoEsquerda = NULL;
		(*node)->elemento = x;
		return true;
	}
	
	if( strcasecmp( (*node)->elemento.termo, x.termo ) == 0 )
		return false;
	
	if( strcasecmp( (*node)->elemento.termo, x.termo ) > 0 ){
		return(insereItem(&(*node)->filhoEsquerda, x));
	}else{
		return(insereItem(&(*node)->filhoDireita, x));
	}
}

bool procuraItem(PtrArvore *node, char *palavra, int page) {
	if (*node == NULL)
		return false;
	
	if (strcasecmp((*node)->elemento.termo, palavra) == 0){
		enfileira(page, &(*node)->elemento.paginas);
		return true;
	}
	
	if( strcasecmp( (*node)->elemento.termo, palavra ) > 0 ){
		return(procuraItem(&(*node)->filhoEsquerda, palavra, page));
	}else{
		return(procuraItem(&(*node)->filhoDireita, palavra, page));
	}
	
}

void EmOrdem(PtrArvore *node, FILE *saida){
	if((*node) == NULL) return;
	
	EmOrdem(&(*node)->filhoEsquerda, saida);
	
	printf("%s,", (*node)->elemento.termo);
	fprintf(saida, "%s,", (*node)->elemento.termo);
	imprimeFila(&(*node)->elemento.paginas, saida);
	EmOrdem(&(*node)->filhoDireita, saida);
}

int main(int argc, char *argv[]) {
	FILE *entrada;
	FILE *saida;
	
	char str[MAXTAM];
	char * pch;
	char delimitadores[] = " ,.:;<>()\n\t\r\f\v\0";
	int i, page=0;
	
	PtrArvore indice;
	Objeto aux;
	
	// checar se os argumentos foram inseridos
	if(argc == 3){
		printf("Arquivo de Entrada: %s\n", argv[1]);
		printf("Arquivo de Saida: %s\n", argv[2]);
	}else{
		printf("\nERRO!\nArgumentos Invalidos.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// checar se o arquivo de entrada e saida são .txt
	if(!checar_arquivo(argv[1])){
		printf("\nERRO!\nArquivo de entrada nao e do tipo .txt.\nEncerrando Execucao.\n");
		exit(1);
	}
	if(!checar_arquivo(argv[2])){
		printf("\nERRO!\nArquivo de saida nao e do tipo .txt.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// abrindo arquivos
	entrada = fopen(argv[1], "r");
	saida = fopen(argv[2], "w");
	
	if(entrada == NULL){
		printf("\nERRO!\nArquivo de entrada nao pode ser aberto.\nEncerrando Execucao.\n");
		exit(1);
	}
	if(saida == NULL){
		printf("\nERRO!\nArquivo de saida nao pode ser aberto.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// checar se o arquivo de entrada nao esta vazio
	char c = fgetc(entrada);
	
	if(c == EOF){
		printf("\nERRO!\nArquivo de entrada esta vazio.\nEncerrando Execucao.\n");
		fprintf(saida, "ERRO!\nArquivo de entrada esta vazio.");
		fclose(entrada);
		fclose(saida);
		exit(1);
	}
	
	// le a primeira linha para receber os termos
	fgets(str, MAXTAM-1, entrada);
	pch = strtok(str, delimitadores);
	
	if(strcasecmp(pch, "termos") != 0){
		printf("ERRO!\nPrimeira linha do arquivo nao possui a tag <termos>.\nEncerrando Execucao.\n");
		fclose(entrada);
		fclose(saida);
		return 1;
	}
	
	iniciaArvore(&indice);
	
	//calcula a qtd de termos e insere na arvore
	for(i = 0; pch != NULL; i++){
		
		//if i > 0 inserir termo na arvore
		if(i > 0){
			strcpy(aux.termo, pch);
			iniciaFila(&aux.paginas);
			
			if(!insereItem(&indice, aux)){
				printf("ERRO!\nTermo ja esta no Indice.\n");
			}
			
		}
		
		pch = strtok (NULL, delimitadores);
	}
	
	if(i <= 1 ){
		printf("ERRO!\nPrimeira linha do arquivo nao possui termos para o indice.\nEncerrando Execucao.\n");
		destroiArvore(&indice);
		fclose(entrada);
		fclose(saida);
		return 1;
	}
	
	while(1){
		if(feof(entrada))
			break;
		
		fgets(str, MAXTAM-1, entrada);
		pch = strtok(str, delimitadores);
		
		for(i = 0; pch != NULL; i++){
			if (strcasecmp(pch, "page") == 0){
				page++;
				break;
			}
			procuraItem(&indice, pch, page);
			// if(procuraItem(&indice, pch, page)){
			// 	printf("pg %i inserido no termo %s\n",page, pch);
			// }
			
			pch = strtok (NULL, delimitadores);
		}
		str[0]='\0';
	}
	
	printf("\n");
	EmOrdem(&indice, saida);
	destroiArvore(&indice);
	// if (estaVaziaArvore(&indice))
	// 	printf("Arvore destruida\n");
	fclose(entrada);
	fclose(saida);
	
	return 0;
}
