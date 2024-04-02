#ifndef __EG3D_H__
#define __EG3D_H__

#include "sl.h"
#include "utils.h"

// Função principal utilizada na main(perfSl). Triangulariza a "matriz"(vetores), em seguida faz a retrosubstituição.
void eg3d(double **m, double *v, int n);

#endif // __EG3D_H__