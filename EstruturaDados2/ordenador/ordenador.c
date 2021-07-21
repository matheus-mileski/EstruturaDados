#include "ordenador.h"

bool checarArquivo(char *arquivo) {
	
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

void nomeSaida(char *original, char *metodo, char *novo){
	int i;
	for(i = 0; i < strlen(original)-4; i++){
		novo[i] = original[i];
	}
	novo[i] = '\0';
	
	strcat(novo,metodo);
	
}

void bubbleSort(int *v, int n, unsigned long long int *c, unsigned long long int *t){
	bool troca = false;
	int fim = n-1;
	int aux;
	
	do{
		troca = 0;
		for(int i = 0; i < fim; i++){
			*c = *c + 1;
			if(v[i] > v[i+1]){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				*t = *t + 1;
				troca = true;
			}
		}
		fim--;
	}while(troca != false);
	
}

void insertionSort(int *v, int n, unsigned long long int *c, unsigned long long int *t){
	// cria as variáveis auxiliares
	int eleito, j;
	
	// loop para percorrer o vetor da posição 1 até o final
	for(int i = 1; i < n; i++){
		// define o valor analisado
		eleito = v[i];
		
		// loop que percorre do valor analisado até a posição 0, voltando
		// para quando chegar a posição 0 ou quando o valor eleito for maior
		// ou igual ao valor na posição j
		for (j = i-1; (j >= 0) && (eleito < v[j]) ; j--) {
			// avança os valores em uma posição
			v[j+1] = v[j];
			*c = *c + 1;
		}
		// ao final, insere o valor analisado (eleito) na posição correta
		v[j+1] = eleito;
		*t = *t + 1;
	}
}

void selectionSort(int *v, int n, unsigned long long int *c, unsigned long long int *t){
	// cria as variáveis auxiliares
	int menor, aux;
	
	// loop para percorrer o vetor até a penultima posição
	for(int i = 0; i < n-1; i++){
		// define que a posição analisada é a menor
		menor = i;
		
		// loop para percorrer o vetor a partir da posição analisada
		for (int j = i+1; j < n; j++) {
			// sempre que for encontrado um valor menor, salva o seu indice na variavel menor
			*c = *c + 1;
			if(v[j] < v[menor])
				menor = j;
		}
		
		// se encontrar um valor menor que o valor da posição analisada, faz a troca
		if( i != menor){
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
			*t = *t + 1;
		}
	}
}

void mergeSort(int *v, int inicio, int fim, unsigned long long int *c, unsigned long long int *t){
	int meio;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		
		mergeSort(v, inicio, meio, c, t);
		mergeSort(v, meio+1, fim, c, t);
		merge(v, inicio, meio, fim, c, t);
	}
}

void merge(int *v, int inicio, int meio, int fim, unsigned long long int *c, unsigned long long int *t){
	int *temp, p1, p2, tamanho, j, k;
	tamanho = fim - inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int *)malloc(tamanho * sizeof(int));

	if(temp != NULL){
		for(int i = 0; i < tamanho; i++){
			*c = *c + 1;
			if(p1 <= meio && p2 <= fim){
				*c = *c + 1;
				if(v[p1] < v[p2]){
					*t = *t + 1;
					temp[i] = v[p1++];
				}else{
					*t = *t + 1;
					temp[i] = v[p2++];
				}
			}else{
				*c = *c + 1;
				if(p1 <= meio){
					*t = *t + 1;
					temp[i] = v[p1++];
				}else{
					*t = *t + 1;
					temp[i] = v[p2++];
				}
			}
		}
		for(j = 0, k = inicio; j < tamanho; j++, k++ ){
			*t = *t + 1;
			v[k] = temp[j];
		}
	}
	
	free(temp);
	
}

void quickSort(int *v, int inicio, int fim, unsigned long long int *c, unsigned long long int *t){

	int pivo;
	if(inicio < fim){
		pivo = particiona(v, inicio, fim, c, t);
		
		quickSort(v, inicio, pivo-1, c , t);
		quickSort(v, pivo+1, fim, c , t);
	}
}

int particiona(int *v, int inicio, int fim, unsigned long long int *c, unsigned long long int *t){
	int esq = inicio;
	int dir = fim;
	int pivo = v[inicio];
	int aux;
	
	while(esq < dir){
		while(v[esq] <= pivo && esq <= fim){
			*c = *c + 1;
			esq++;
		}
		while(v[dir] > pivo && dir >= inicio){
			*c = *c + 1;
			dir--;
		}
		*c = *c + 1;
		if (esq < dir){
			*t = *t + 1;
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	*t = *t + 1;
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

void heapSort(int *v, int n, unsigned long long int *c, unsigned long long int *t){
	int aux;
	for(int i = (n-1)/2; i >= 0; i--){
		criaHeap(v, i, n-1, c, t);
	}
	
	for(int i = n-1; i >= 1; i--){
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
		*t = *t + 1;
		criaHeap(v, 0 , i-1, c, t);
	}
}

void criaHeap(int *v, int pai, int fim, unsigned long long int *c, unsigned long long int *t){
	int aux = v[pai];
	int filho = pai*2 + 1;
	
	while(filho <= fim){
		*c = *c + 1;
		if(filho < fim && v[filho] < v[filho+1])
			filho++;
		
		*c = *c + 1;
		if(aux < v[filho]){
			v[pai] = v[filho];
			pai = filho;
			filho = pai*2 + 1;
			*t = *t + 1;
		}else
			filho = fim +1;
	}
	v[pai] = aux;
}

int main(int argc, char *argv[]) {
	
	clock_t ticks[8];
	double tempo;
	
	ticks[0] = clock();
	
	FILE *entrada;
	FILE *saida;
	
	char metodo[101];
	char nomeArquivo[101];
	
	unsigned long long int comp = 0;
	unsigned long long int troca = 0;
	
	int n = 1;
	int *v = (int*) malloc(n * sizeof (int));
	
	// checar se os argumentos foram inseridos
	if(argc != 3){
		printf("\nERRO!\nArgumentos Invalidos.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// checar se o argumento do algoritmo é válido
	if(argv[1][0] != 'b' && argv[1][0] != 'B' &&
		argv[1][0] != 'i' && argv[1][0] != 'I' &&
		argv[1][0] != 's' && argv[1][0] != 'S' &&
		argv[1][0] != 'm' && argv[1][0] != 'M' &&
		argv[1][0] != 'q' && argv[1][0] != 'Q' &&
		argv[1][0] != 'h' && argv[1][0] != 'H'){
		
		printf("\nERRO!\nOpcao de algoritmo invalido\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// checar se o arquivo de entrada é .txt
	if(!checarArquivo(argv[2])){
		printf("\nERRO!\nArquivo de entrada nao e do tipo .txt.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// abrindo arquivo de entrada
	entrada = fopen(argv[2], "r");
	
	if(entrada == NULL){
		printf("\nERRO!\nArquivo de entrada nao pode ser aberto.\nEncerrando Execucao.\n");
		exit(1);
	}
	
	// checar se o arquivo de entrada nao esta vazio
	if(fgetc(entrada) == EOF){
		printf("\nERRO!\nArquivo de entrada esta vazio.\nEncerrando Execucao.\n");
		fclose(entrada);
		exit(1);
	}
	
	fseek(entrada,0,SEEK_SET);
	
	ticks[4] = clock();
	while(1){
		if(n > 1)
			v = (int*)realloc(v, n * sizeof (int));
		
		fscanf(entrada, "%i\n", &v[n - 1]);
		
		if(feof(entrada))
			break;
		else
			n++;
	}
	
	fclose(entrada);
	ticks[5] = clock();
	
	switch (argv[1][0]) {
		case 'b':
		case 'B':
			printf("BubbleSort\n");
			
			ticks[2] = clock();
			bubbleSort(v, n, &comp, &troca);
			ticks[3] = clock();
			
			strcpy(metodo,"_BubbleSort.txt");
			
			break;
		case 'i':
		case 'I':
			printf("InsertionSort\n");
			
			ticks[2] = clock();
			insertionSort(v, n, &comp, &troca);
			ticks[3] = clock();
			
			strcpy(metodo,"_InsertionSort.txt");
			
			break;
		case 's':
		case 'S':
			printf("SelectionSort\n");
			
			ticks[2] = clock();
			selectionSort(v, n, &comp, &troca);
			ticks[3] = clock();
			
			strcpy(metodo,"_SelectionSort.txt");
			
			break;
		case 'm':
		case 'M':
			printf("MergeSort\n");
			
			ticks[2] = clock();
			mergeSort(v, 0, n - 1, &comp, &troca);
			ticks[3] = clock();
			
			strcpy(metodo,"_MergeSort.txt");
			
			break;
		case 'q':
		case 'Q':
			printf("QuickSort\n");
			
			ticks[2] = clock();
			quickSort(v, 0, n - 1, &comp, &troca);
			ticks[3] = clock();
			
			strcpy(metodo,"_QuickSort.txt");
			
			break;
		case 'h':
		case 'H':
			printf("HeapSort\n");
			
			ticks[2] = clock();
			heapSort(v, n, &comp, &troca);
			ticks[3] = clock();
			
			strcpy(metodo,"_HeapSort.txt");
			
			break;
		default:
			printf("\nERRO!\nOpcao Invalida.\nEncerrando Execucao.\n");
			free(v);
			exit(1);
	}
	
	// abrindo arquivo de saida
	nomeSaida(argv[2], metodo, nomeArquivo);
	saida = fopen(nomeArquivo, "w");
	
	if(saida == NULL){
		printf("\nERRO!\nArquivo de saida nao pode ser aberto.\nEncerrando Execucao.\n");
		free(v);
		fclose(saida);
		exit(1);
	}
	
	ticks[6] = clock();
	for(int i = 0; i < n; i++) {
		fprintf(saida, "%i\n", v[i]);
	}
	ticks[7] = clock();
	
	ticks[1] = clock();
	
	printf("Numeros Ordenados: %i\n", n);
	
	printf("Quantidade de Comparacoes: %llu\n", comp);
	printf("Quantidade de trocas: %llu\n", troca);
	
	tempo = (double)(ticks[1] - ticks[0])*1000 / (CLOCKS_PER_SEC);
	printf("Tempo Total: %.3lf ms.\n", tempo);
	
	tempo = (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC);
	printf("Tempo Ordenacao: %.3lf ms.\n", tempo);
	
	tempo = (double)(ticks[5] - ticks[4])*1000 / (CLOCKS_PER_SEC);
	printf("Tempo Leitura: %.3lf ms.\n", tempo);
	
	tempo = (double)(ticks[7] - ticks[6])*1000 / (CLOCKS_PER_SEC);
	printf("Tempo Escrita: %.3lf ms.\n", tempo);
	
	free(v);
	fclose(saida);
	
	return 0;
}
