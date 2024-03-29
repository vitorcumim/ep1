#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void retrosub(double **m, double *v, double *resultado, int n);

void eliminacao_gauss(double **m, double *v, int n);

void eg(double **m, double *v, double *resultado, double *residuo, int n);