/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#ifndef __GS3D_H__
#define __GS3D_H__

#include "sl.h"

// Função principal utilizada na main(perfSl) calcula os resultado utilizando o método de Gauss Seidel para uma matriz tridiagonal e imprime.
void gs3d(double **m, double *v, int n);

#endif // __GS3D_H__