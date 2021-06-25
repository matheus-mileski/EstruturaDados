#ifndef ESTRUTURADADOS_MERGESORT_H
#define ESTRUTURADADOS_MERGESORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);
void imprimirVetor(int *v, int inicio, int fim);

#endif //ESTRUTURADADOS_MERGESORT_H
