#include "eg3d.h"

// Realiza a retrosubstituição na "matriz"(vetores) tridiagonal.
void retrosub(double *d, double*c, double *v, double *resultado, int n) {
	
	resultado[n-1] = v[n-1] / d[n-1];
	for (int i = n-2; i >= 0; --i)
		resultado[i] = (v[i] - c[i] * resultado[i+1]) / d[i];
}

// Realiza a triangularizção da "matriz"(vetores) tridiagonal.
void triangulariza(double *d, double *a, double *c, double *v, int n) {

	for (int i = 0; i < n-1; ++i) {
		double coef = a[i] / d[i];
		a[i] = 0.0;
		d[i+1] -= c[i] * coef;
		v[i+1] -= v[i] * coef;
	}
}

// Pega as três diagonais da matriz tridiagonal e coloca ela em três vetores.
void gera_vetores(double **m, double *a, double *d, double *c, int n) {

    for (int i = 0; i < n; i++)							// A diagonal principal está na diagonal 0
        d[i] = m[i][i];

    for (int i = 0; i < n-1; i++)					 	// A primeira diagonal superior está na diagonal 1
        c[i] = m[i][i+1];

    for (int i = 0; i < n-1; i++)						 // A primeira diagonal inferior está na diagonal -1
        a[i] = m[i+1][i];
}

// Função principal utilizada na main(perfSl). Triangulariza a "matriz"(vetores), em seguida faz a retrosubstituição.
void eg3d(double **m, double *v, int n) {
	double *a, *d, *c, *resultado, *residuo;
	double tempo = 0.0;

	a = aloca_vetor(n-1);									// Aloca memória para os vetores da matriz tridiagonal.
	d = aloca_vetor(n);
	c = aloca_vetor(n-1);
	
	resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(residuo,0,n*sizeof(double));						// Preenche o vetor de reíduos com zeros.(somente na eliminação de gauss).

	gera_vetores(m,a,d,c,n);								// Transforma a matriz tridiagonal em três vetores.
	tempo = timestamp();
	triangulariza(d,a,c,v,n);
	retrosub(d,c,v,resultado,n);
	tempo = timestamp() - tempo;
	printf("EG 3-diagonal:\n");
	imprimeresultado(resultado,residuo,tempo,n);
	destroi_vetor(a,n-1);										// Libera toda a memória usada.			
	destroi_vetor(d,n);
	destroi_vetor(c,n-1);
	destroi_vetor(residuo,n);
	destroi_vetor(resultado,n);
}

/*int main() {
	double **m;
	double *v;
	int n;
	
	le_sl(&m,&v,&n);
	
	eg3d(m,v,n);

	destroi_sl(m,v,n);
	return 0;
}*/