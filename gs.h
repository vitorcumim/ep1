#ifndef __GS_H__
#define __GS_H__

#include "sl.h"
#include "utils.h"
#define TOL 1e-9

// Função principal utilizada na main(perfSl). 
void gs(double **m, double *v, int n);

#endif // __GS_H__