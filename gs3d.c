/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#include "gs3d.h"
#include <likwid.h>

// Função que implementa o metódo de Gauss Seidel para uma matriz tridiagonal.
void gaussSeidel3d(double *d, double *a, double *c, double *v, double *resultado, int n, int *it) {
	double *ex_resultado, erro = 1.0 + TOL;
 	
 	ex_resultado = aloca_vetor(n);
 	memset(ex_resultado,0,n*sizeof(double));

 	while (erro > TOL && (*it) < 50) {
 		resultado[0] = (v[0] - c[0] * resultado[1]) / d[0];
 		for (int i = 1; i < n-1; ++i)
 			resultado[i] = (v[i] - a[i-1] * resultado[i-1] - c[i] * resultado[i+1]) / d[i];
 		resultado[n-1] = (v[n-1] - a[n-2] * resultado[n-2] ) / d[n-1];
 		erro = calculaErro(resultado,ex_resultado,n);
		(*it) ++;
	}
	destroi_vetor(ex_resultado);
 }

// Função principal utilizada na main(perfSl) calcula os resultado utilizando o método de Gauss Seidel para uma matriz tridiagonal e imprime.
void gs3d(double **m, double *v, int n) { 
    double *a, *d, *c, *resultado, *residuo;
    double tempo;
    int it = 0;

    a = aloca_vetor(n-1);                                    // Aloca memória para os vetores da matriz tridiagonal.
    d = aloca_vetor(n);
    c = aloca_vetor(n-1);

    resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(resultado,0,n*sizeof(double));					// Preenche o vetor de resultado com zeros.
	memset(residuo,0,n*sizeof(double));						// Preenche o vetor de reíduos com zeros.

	gera_vetores3d(m,a,d,c,n);								// Transforma a matriz tridiagonal em três vetores.
    LIKWID_MARKER_START("GS_3_diagonal");
    tempo = timestamp();
    gaussSeidel3d(d,a,c,v,resultado,n,&it);
    tempo = timestamp() - tempo;
    LIKWID_MARKER_STOP("GS_3_diagonal");
    calculaResiduo(m,v,resultado,residuo,n);				// Calcula o resíduo.
    printf("GS 3-diagonal [ %d iterações ]:\n",it);
    imprimeresultado(resultado,residuo,tempo,n);			// Imprime os resultados.
    destroi_vetor(a);										// Libera toda a memória usada pelos vetore a, d, c .			
	destroi_vetor(d);
	destroi_vetor(c);
    destroi_vetor(residuo);									// Libera a memória utilizada pelo vetor resíduo.
    destroi_vetor(resultado);								// Libera a memória utilizada pelo vetor resultado.
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