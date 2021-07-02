#ifndef ESTRUTURADADOS_HEAPSORT_H
#define ESTRUTURADADOS_HEAPSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/**
* \brief Ordena o vetor usando HeapSort
*
* \param v vetor a ser ordenado
* \param n tamanho do vetor
*
* Ordena o vetor usando o método HeapSort
*/
void heapSort(int *v, int n);

/**
* \brief Transforma um heap em maxheap
*
* \param v vetor a ser particionado
* \param pai índice do nó raiz do heap
* \param fim índice do último elemento do heap
*
*/
void criaHeap(int *v, int pai, int fim);

void imprimirVetor(int *v, int inicio, int fim);

#endif //ESTRUTURADADOS_HEAPSORT_H
