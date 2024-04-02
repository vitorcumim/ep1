#ifndef __EG_H__
#define __EG_H__

#include "sl.h"
#include "utils.h"

// Função principal utilizada na main(perfSl). Triangulariza a matriz, em seguida faz a retrosubstituição.
void eg(double **m, double *v, int n);

#endif // __EG_H__