#ifndef ESTRUTURADADOS_QUICKSORT_H
#define ESTRUTURADADOS_QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

/**
* \brief Ordena o vetor usando QuickSort
*
* \param v vetor a ser ordenado
* \param inicio índice do início do vetor
* \param fim índice do final do vetor
*
* Ordena o vetor usando o método QuickSort
* Esse algoritmo tem um comportamento assintótico O(n log n)
*/
void quickSort(int *v, int inicio, int fim);

/**
* \brief Particiona o vetor
*
* \param v vetor a ser particionado
* \param inicio índice do início do vetor
* \param fim índice do final do vetor
*
* \return pivo indice do pivo na posição correta
*
* Calcula o pivô e rearranja os dados em
* menores que o pivô a esquerda, maiores que
* o pivô a direita
*/
int particiona(int *v, int inicio, int fim);
int particionaAlt(int *v, int inicio, int fim);

void imprimirVetor(int *v, int inicio, int fim);

#endif //ESTRUTURADADOS_QUICKSORT_H
