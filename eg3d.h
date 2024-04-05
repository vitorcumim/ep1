/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#ifndef __EG3D_H__
#define __EG3D_H__

#include "sl.h"

// Função principal utilizada na main(perfSl). Triangulariza a "matriz"(vetores), em seguida faz a retrosubstituição.
void eg3d(double **m, double *v, int n);

#endif // __EG3D_H__