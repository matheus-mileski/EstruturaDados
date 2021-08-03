#ifndef ESTRUTURADADOS_CADASTROINDEXADO_H
#define ESTRUTURADADOS_CADASTROINDEXADO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
	int rrn;
	int id;
} IndiceP;

#define RRN_TAM     64
#define ID          0
#define NOME        4
#define IDADE       35
#define MODALIDADE  38

#endif //ESTRUTURADADOS_CADASTROINDEXADO_H
