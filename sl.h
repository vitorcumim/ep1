#include <stdio.h>
#include <stdlib.h>

// Aloca espaço na memória para um vetor com tamanho n.
double *aloca_vetor(int n);

// Aloca espaço na memória para uma matriz de tamanho n*n.
double **aloca_matriz(int n);

// Lê um sistema linear. Uma matrix n*n e um vetor n.
void le_sl(double ***m, double **v, int *n);

// Copia o vetor v para o vetor vx (DEBUG).
void criacopia_vetor(double *v, double **vx, int n); //DEBUG

// Copia a matriz m para a matriz mx (DEBUG).
void criacopia_matriz(double **m, double ***mx, int n); //DEBUG

// Copia o sistema linear (m,v) para o sistema linear (mx,vx).
void criacopia_sl(double **m, double ***mx, double *v, double **vx, int n);

// Imprime os vetores resultado, resíduo e o tempo.
void imprimeresultado(double *resultado, double *residuo, double tempo, int n);

// Libera a memória usada por um vetor (DEBUG).
void destroi_vetor(double *v, int n); //DEBUG

// Libera a memória usada por uma matriz (DEBUG).
void destroi_matriz(double **m, int n); //DEBUG

// Libera a memória usada por um sistema linear (uma matriz e um vetor). 
void destroi_sl(double **m, double *v, int n); 

// Libera toda a memória utilizada para cada método.
void destroi_tudo(double **m, double *v, double *residuo, double *resultado, int n);

// Imprime uma matriz (DEBUG).
void imprime_matriz(double **m, int n); //DEBUG