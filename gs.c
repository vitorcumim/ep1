/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#include "gs.h"
#include <likwid.h>

// O VALOR TOL(TOLERÂNCIA DO ERRO) E MAXIT(MÁXIMO DE ITERAÇÔES) ESTÃO DEFINIDOS NA BIBLIOTECA "utils.h".

// NESSA BIBLIOTECA, EM TODAS FUNÇÔES, N SE REFERE AO GRAU DA MATRIZ.

// Função que executa o método de Gauss Seidel para o sistema linear (m,v), preeche o vetor resultado e altera o número de iterações(it).
void gaussSeidel(double **m, double *v, double *resultado, int n, int *it) {
	double *ex_resultado, s, erro = 1 + TOL;
	int j;

	ex_resultado = aloca_vetor(n);							// Aloca um vetor para guardar os resultados das iterações (k-1).
	memset(ex_resultado,0,n*sizeof(double));				// No início a interação (k-1) é nula = vetor de zeros.

	while (erro > TOL && (*it) < MAXIT) {
		for (int i = 0; i < n; ++i) {
			for (s = 0, j = 0; j < n; ++j){
				if (i != j)
					s += (m[i][j] * resultado[j]);
			}
			resultado[i] = (v[i] - s) / m[i][i];
		}
		erro = calculaErro(resultado,ex_resultado,n);		// Calcula o erro com base na iteração atual(k) e na anterior(k-1).
		(*it) ++;
	}	
	destroi_vetor(ex_resultado);
}

// Função principal utilizada na main(perfSl) resolve o sistema linear (m,v) de grau n utilizando o método de Gauss Seidel e imprime.
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