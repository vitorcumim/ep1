/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#include "eg3d.h"
#include <likwid.h>

// NESSA BIBLIOTECA, EM TODAS FUNÇÕES, N SE REFERE AO GRAU DA MATRIZ.

// Realiza a retrosubstituição no "sistema linear"(d,c,v) tridiagonal.
void retrosub3d(double *d, double*c, double *v, double *resultado, int n) {
	
	resultado[n-1] = v[n-1] / d[n-1];
	for (int i = n-2; i >= 0; --i)
		resultado[i] = (v[i] - c[i] * resultado[i+1]) / d[i];
}

// Realiza a triangularizção do "sistema linear"(d,a,c,v) tridiagonal.
void triangulariza3d(double *d, double *a, double *c, double *v, int n) {

	for (int i = 0; i < n-1; ++i) {
		double coef = a[i] / d[i];
		a[i] = 0.0;
		d[i+1] -= c[i] * coef;
		v[i+1] -= v[i] * coef;
	}
}

// Função principal utilizada na main(perfSl). Triangulariza o sitema linear(m,v) de grau n tridiagonal, em seguida faz a retrosubstituição.
void eg3d(double **m, double *v, int n) {
	double *a, *d, *c, *resultado, *residuo, *vx;
	double tempo;

	a = aloca_vetor(n-1);									// Aloca memória para os vetores da matriz tridiagonal.
	d = aloca_vetor(n);										// d = diagonal principa, c = diagonal superio, a = diagonal inferior.
	c = aloca_vetor(n-1);
	criacopia_vetor(v,&vx,n);								// Aloca e copia o vetor de resultados do sitema linear para um vetor auxiliar.
	
	resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(resultado,0,n*sizeof(double));					// Preenche o vetor de resultado com zeros.
	memset(residuo,0,n*sizeof(double));						// Preenche o vetor de reíduos com zeros.

	gera_vetores3d(m,a,d,c,n);								// Transforma a matriz tridiagonal em três vetores.
	LIKWID_MARKER_START("EG_3_diagonal");
	tempo = timestamp();
	triangulariza3d(d,a,c,vx,n);
	retrosub3d(d,c,vx,resultado,n);
	tempo = timestamp() - tempo;
	LIKWID_MARKER_STOP("EG_3_diagonal");
	calculaResiduo(m,v,resultado,residuo,n);				// Calcula o resíduo.
	printf("EG 3-diagonal:\n");
	imprimeresultado(resultado,residuo,tempo,n);			// Imprime os resultado.
	destroi_vetor(a);										// Libera toda a memória usada.			
	destroi_vetor(d);
	destroi_vetor(c);
	destroi_vetor(vx);
	destroi_vetor(residuo);
	destroi_vetor(resultado);
}