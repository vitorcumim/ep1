/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#include "gs.h"
#include <likwid.h>

// Função que executa o método de Gauss Seidel.
void gaussSeidel(double **m, double *v, double *resultado, uint n, int *it) {
	double *ex_resultado, s, erro = 1 + TOL;
	int j;

	ex_resultado = aloca_vetor(n);
	memset(ex_resultado,0,n*sizeof(double));

	while (erro > TOL && (*it) < 50) {
		for (int i = 0; i < n; ++i) {
			for (s = 0, j = 0; j < n; ++j){
				if (i != j)
					s += (m[i][j] * resultado[j]);
			}
			resultado[i] = (v[i] - s) / m[i][i];
		}
		erro = calculaErro(resultado,ex_resultado,n);
		(*it) ++;
	}
	
	destroi_vetor(ex_resultado);
}

// Função principal utilizada na main(perfSl) calcula os resultado utilizando o método de Gauss Seidel e imprime.
void gs(double **m, double *v, int n) { 
	double *resultado, *residuo;
	double tempo;
	int it = 0;

	resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(resultado,0,n*sizeof(double));					// Preenche o vetor de resultado com zeros.
	memset(residuo,0,n*sizeof(double));						// Preenche o vetor de reíduos com zeros.

	LIKWID_MARKER_START("GS_clássico");
	tempo = timestamp();
	gaussSeidel(m,v,resultado,n,&it);
	tempo = timestamp() - tempo;
	LIKWID_MARKER_STOP("GS_clássico");
	calculaResiduo(m,v,resultado,residuo,n);				// Calcula os resíduos.
	printf("GS clássico  [ %d iterações ]:\n",it);
	imprimeresultado(resultado,residuo,tempo,n);			// Imprime os resultados.
	destroi_vetor(residuo);									// Libera a memória usa por resíduo.
	destroi_vetor(resultado);								// Libera a memória usa por resultado.
}

/*int main() {
	double **m;
	double *v;
	int n; 
	
	le_sl(&m,&v,&n);
	
	gs(m,v,n);
	
	destroi_sl(m,v,n);
	return 0;
}*/