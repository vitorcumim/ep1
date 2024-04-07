/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#ifndef __EG_H__
#define __EG_H__

#include "sl.h"

// Função principal utilizada na main(perfSl). Triangulariza o sistema linear(m,v) de grau n em seguida faz a retrosubstituição e imprime o resultado e o resíduo.
void eg(double **m, double *v, int n);

#endif // __EG_H__