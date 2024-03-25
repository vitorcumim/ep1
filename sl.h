#ifndef __SL__
#define __SL__

#include <stdio.h>
#include <stdlib.h>

double** aloca_matriz(int n);

double* aloca_vetor(int n);

void le_sl(double ***m, double **v, int *n);

void criacopia_matriz(double **m, double ***mx, int n);

void criacopia_vetor(double *v, double **vx, int n);

void imprimeresultado(double *resultado, double *residuo, double tempo, int n);

void destroi_matriz(double **m, int n);

void destroi_vetor(double *v, int n);

void destroi_tudo(double **m, double **mx, double *v, double *vx, double *residuo, double *resultado, int n);

void imprime_matriz(double **m,int n); //debug excluir dps

#endif