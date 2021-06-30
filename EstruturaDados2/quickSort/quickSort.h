#ifndef ESTRUTURADADOS_QUICKSORT_H
#define ESTRUTURADADOS_QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include<time.h>

void quickSort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int fim);
int particionaAlt(int *v, int inicio, int fim);
void imprimirVetor(int *v, int inicio, int fim);

#endif //ESTRUTURADADOS_QUICKSORT_H
