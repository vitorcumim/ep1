//	Nome: Rafael Urbanek Laurentino
// 	GRR: 20224381
// 	Nome: Vitor Lorenzo Cumim
// 	GRR: 20224757

#ifndef __SL_H__
#define __SL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Aloca espaço na memória para um vetor com tamanho n.
double *aloca_vetor(int n);

// Aloca espaço na memória para uma matriz de tamanho n*n.
double **aloca_matriz(int n);

// Lê um sistema linear. Uma matrix(m) n*n, e um vetor(v) de tamanho n.
void le_sl(double ***m, double **v, int *n);

// Copia o vetor v para o vetor vx.
void copia_vetor(double *v,double *vx,int n);

// Aloca e copia o vetor v para o vetor vx (DEBUG).
void criacopia_vetor(double *v, double **vx, int n); //DEBUG

// Aloca e copia a matriz m para a matriz mx (DEBUG).
void criacopia_matriz(double **m, double ***mx, int n); //DEBUG

// Aloca e copia o sistema linear (m,v) para o sistema linear (mx,vx).
void criacopia_sl(double **m, double ***mx, double *v, double **vx, int n);

// Calcula resíduo baseado na formula residuo = m * resultado - v.
void calculaResiduo(double **m, double *v, double *resultado, double *residuo, int n);

// Coloca as três diagonais da matriz tridiagonal em vetores, diagonal principal = d; diagonal inferior = a; diagonal superior = c.
void gera_vetores3d(double **m, double *a, double *d, double *c, int n);

// Função responsável por calcular o erro aproximado.
double calculaErro(double *resultado, double *ex_resultado, int n);

// Imprime os vetores resultado, resíduo e o tempo.
void imprimeresultado(double *resultado, double *residuo, double tempo, int n);

// Libera a memória usada por um vetor (DEBUG).
void destroi_vetor(double *v); //DEBUG

// Libera a memória usada por uma matriz (DEBUG).
void destroi_matriz(double **m, int n); //DEBUG

// Libera a memória usada por um sistema linear (uma matriz e um vetor). 
void destroi_sl(double **m, double *v, int n); 

// Libera toda a memória utilizada para cada método.
void destroi_tudo(double **m, double *v, double *residuo, double *resultado, int n);

// Imprime uma matriz (DEBUG).
void imprime_matriz(double **m, int n); //DEBUG

#endif // __SL_H__