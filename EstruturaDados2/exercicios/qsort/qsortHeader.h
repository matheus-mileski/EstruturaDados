#ifndef ESTRUTURADADOS_QSORTHEADER_H
#define ESTRUTURADADOS_QSORTHEADER_H

/**
 *	\brief 	Exercicio qsort:
 *			1) Crie uma estrutura representando um atleta de
 *			corrida. Essa estrutura deve conter o nome do atleta,
 *			seu país, idade, altura e tempo (em segundos com casas decimais).
 *			Em seguida, escreva um programa que leia do teclado os
 *			dados de oito atletas e os armazene em um arquivo texto.
 *			2) Considerando a estrutura atleta do exercício anterior:
 *			a) Escreva um outro programa que lê o arquivo gerado e
 *			armazene em um vetor de estruturas.
 *			b) Utilizando a função qsort ordene os atletas pelo tempo
 *			(mais rápido primeiro)
 *			c) Armazene atletas ordenados pelo tempo em um outro arquivo
 *			utilizando a técnica de Dados formatados.
 *			d) Utilizando a função qsort ordene os atletas pelo nome (a-z)
 *			e) Armazene atletas ordenados pelo nome em um outro arquivo
 * 			utilizando a técnica de Dados formatados.
 *
 *			Dados dos atletas da última corrida do Usain Bolt, em 2017.
 *			https://www.flotrack.org/articles/5967326-usain-bolt-loses-his-last-ever-worlds-100m-race-to-justin-gatlin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[25];
	char pais[25];
	int idade;
	int altura;
	float tempo;
}Atleta;

/**
 * \brief  	limpa_buffer:
 * 			Função para limpar o buffer do teclado após o uso de scanf.
 */
void limpa_buffer();

/**
 * \brief  	imprimeAtleta:
 * 			Função que imprime as informações do atleta.
 *
 * \param i: índice do atleta a ser impresso.
 * \param corredor: estrutura referente ao atleta que será impresso.
 * \param arq: arquivo para armazenar as informações do atleta,
 * 				se arq for NULL não executará o fprintf.
 */
void imprimeAtleta(int i, Atleta corredor, FILE *arq);

/**
 * \brief  	comparaTempo:
 * 			Função compar para o qsort(),
 * 			ordena os atletas pelo menor tempo.
 *
 * \param a: recebe o endereço do primeiro valor para comparação.
 * \param b: recebe o endereço do segundo valor para comparação.
 *
 * \return 0: se a e b forem iguais.
 * \return -1: se a < b.
 * \return 1: se a > b.
 */
int comparaTempo(const void *a, const void *b);

/**
 * \brief  	comparaNome:
 * 			Função compar para o qsort(),
 * 			ordena os atletas em ordem alfabética utilizando strcmp.
 *
 * \param a: recebe o primeiro valor para comparação.
 * \param b: recebe o segundo valor para comparação.
 *
 * \return 0: se a e b forem iguais.
 * \return -1: se a < b.
 * \return 1: se a > b.
 */
int comparaNome(const void *a, const void *b);

#endif //ESTRUTURADADOS_QSORTHEADER_H
