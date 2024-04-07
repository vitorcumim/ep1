/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#ifndef __GS3D_H__
#define __GS3D_H__

#include "sl.h"

// Função principal utilizada na main(perfSl) resolve o sistema linear (m,v) de grau n tridiagonal utilizando o método de Gauss Seidel e imprime.
void gs3d(double **m, double *v, int n);

#endif // __GS3D_H__