/**
 * @file 	ordenacao.h
 * @author 	Matheus Mileski
 * @date 	21 Jul 2021
 * @brief 	Implementação dos métodos de ordenação
 *
 * Implementa os métodos de ordenação vistos na disciplina
 * Estrutura de Dados 2.
 */

#ifndef ESTRUTURADADOS_ORDENADOR_H
#define ESTRUTURADADOS_ORDENADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/**
 * @brief Checar formato do arquivo
 *
 * @param arquivo nome do arquivo a ser verificado
 *
 * @return true caso o arquivo seja .txt
 *
 * Acessa os 4 últimos caracteres do nome do arquivo e
 * verifica se correspondem ao valor .txt.
 */
bool checarArquivo(char *arquivo);

/**
 * @brief Cria o nome do arquivo de saída
 *
 * @param original nome do arquivo de entrada original
 * @param metodo nome do método de ordenação
 * @param novo string que receberá o nome do arquivo de saída após a concatenação
 *
 * Copia o nome do arquivo de entrada sem os 4 últimos caracteres,
 * que correspondem ao tipo de arquivo, e concatenam com o método
 * de ordenação escolhido.
 */
void nomeSaida(char *original, char *metodo, char *novo);

/**
 * @brief Ordena o vetor usando BubbleSort
 *
 * @param v vetor a ser ordenado
 * @param n tamanho do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Ordena o vetor usando o método BubbleSort.
 * Esse algoritmo tem um comportamento assintótico O(n²).
 */
void bubbleSort(int *v, int n, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Ordena o vetor usando InsertionSort
 *
 * @param v vetor a ser ordenado
 * @param n tamanho do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Ordena o vetor usando o método InsertionSort.
 * Esse algoritmo tem um comportamento assintótico O(n²).
 */
void insertionSort(int *v, int n, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Ordena o vetor usando SelectionSort
 *
 * @param v vetor a ser ordenado
 * @param n tamanho do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Ordena o vetor usando o método SelectionSort.
 * Esse algoritmo tem um comportamento assintótico O(n²).
 */
void selectionSort(int *v, int n, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Ordena o vetor usando MergeSort
 *
 * @param v vetor a ser ordenado
 * @param inicio índice do início do vetor
 * @param fim índice do final do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Ordena o vetor usando o método MergeSort.
 * Esse algoritmo tem um comportamento assintótico O(n log n).
 */
void mergeSort(int *v, int inicio, int fim, unsigned long long int *c, unsigned long long int *t);

 /**
 * @brief Intercala dois vetores
 *
 * @param v vetor a ser intercalado
 * @param inicio índice do início do vetor
 * @param meio índice do último elemento do primeiro vetor
 * @param fim índice do final do segundo vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Intercala um vetor dividido em duas partes de maneira ordenada.
 */
void merge(int *v, int inicio, int meio, int fim, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Ordena o vetor usando QuickSort
 *
 * @param v vetor a ser ordenado
 * @param inicio índice do início do vetor
 * @param fim índice do final do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Ordena o vetor usando o método QuickSort.
 * Esse algoritmo tem um comportamento assintótico O(n log n).
 */
void quickSort(int *v, int inicio, int fim, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Particiona o vetor
 *
 * @param v vetor a ser particionado
 * @param inicio índice do início do vetor
 * @param fim índice do final do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * @return pivo indice do pivo na posição correta
 *
 * Calcula o pivô e rearranja os dados menores que o pivô a esquerda, maiores que
 * o pivô a direita.
 */
int particiona(int *v, int inicio, int fim, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Ordena o vetor usando HeapSort
 *
 * @param v vetor a ser ordenado
 * @param n tamanho do vetor
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Ordena o vetor usando o método HeapSort.
 * Esse algoritmo tem um comportamento assintótico O(n log n).
 */
void heapSort(int *v, int n, unsigned long long int *c, unsigned long long int *t);

/**
 * @brief Transforma um heap em maxheap
 *
 * @param v vetor a ser particionado
 * @param pai índice do nó raiz do heap
 * @param fim índice do último elemento do heap
 * @param c ponteiro para a variável contadora de comparações
 * @param t ponteiro para a variável contadora de trocas
 *
 * Verifica se um dos filhos é maior que o pai e em caso
 * afirmativo, troca o maior filho com o pai, transformando
 * o heap em max heap.
 */
void criaHeap(int *v, int pai, int fim, unsigned long long int *c, unsigned long long int *t);

#endif //ESTRUTURADADOS_ORDENADOR_H
