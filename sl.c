/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#include "sl.h"

// Aloca espaço na memória para um vetor com tamanho n.
double *aloca_vetor(int n) {
	double *v;

	v = malloc(sizeof(double) * n);
	return v;
}

// Aloca espaço na memória para uma matriz de tamanho n*n.
double **aloca_matriz(int n) {
	double **m;

	m = malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++) 
		m[i] = malloc(sizeof(double) * n);
	
	return m;
}

// Lê um sistema linear. Uma matrix(m) n*n, e um vetor(v) de tamanho n. 
void le_sl(double ***m, double **v, int *n) {

	scanf("%d",n);
	getchar();
	
	*m = aloca_matriz(*n);	
	*v = aloca_vetor(*n);

	for (int i = 0; i < *n ; i++) {
		for (int j = 0; j < *n; j++) {
			scanf("%lf",&((*m)[i][j]));
		}
		scanf("%lf",&((*v)[i]));
		getchar();
	}
}

// Copia o vetor v para o vetor vx.
void copia_vetor(double *v,double *vx,int n) {
		for (int i = 0; i < n; i++){
			vx[i] = v[i];
	}
}

// Aloca e copia o vetor v para o vetor vx.
void criacopia_vetor(double *v, double **vx, int n) {
	*vx = aloca_vetor(n);

	copia_vetor(v,*vx,n);
}

// Aloca e copia a matriz m para a matriz mx (DEBUG).
void criacopia_matriz(double **m, double ***mx, int n) {
	*mx = aloca_matriz(n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			(*mx)[i][j] = m[i][j];
	}
}

// Aloca e copia o sistema linear (m,v) para o sistema linear (mx,vx).
void criacopia_sl(double **m, double ***mx, double *v, double **vx, int n) {
	
	*mx = aloca_matriz(n);
	*vx = aloca_vetor(n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			(*mx)[i][j] = m[i][j];
	}

	for (int i = 0; i < n; i++){
			(*vx)[i] = v[i];
	}
}

// Calcula resíduo baseado na formula residuo = m * resultado - v.
void calculaResiduo(double **m, double *v, double *resultado, double *residuo, int n) {

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++)
			residuo[i] += m[i][j] * resultado[j];
		residuo[i] -= v[i];
	}
}

// Coloca as três diagonais da matriz tridiagonal em vetores, diagonal principal = d; diagonal inferior = a; diagonal superior = c.
void gera_vetores3d(double **m, double *a, double *d, double *c, int n) {

    for (int i = 0; i < n; i++)							// A diagonal principal está na diagonal 0
        d[i] = m[i][i];

    for (int i = 0; i < n-1; i++)					 	// A primeira diagonal superior está na diagonal 1
        c[i] = m[i][i+1];

    for (int i = 0; i < n-1; i++)						 // A primeira diagonal inferior está na diagonal -1
        a[i] = m[i+1][i];
}

// Função responsável por calcular o erro aproximado.
double calculaErro(double *resultado, double *ex_resultado, int n) {
	double diff, maior = 0.0;
	
	for (int i = 0; i < n; i++) {							// Encontra o maior erro aproximado.
		diff = ABS(resultado[i] - ex_resultado[i]);
		if (maior < diff)
			maior = diff;
	}

	copia_vetor(resultado,ex_resultado,n);					// Atualiza o vetor de resultados (k-1).
	return maior;
}

// Imprime os vetores resultado, resíduo e o tempo.
void imprimeresultado(double *resultado, double *residuo, double tempo, int n) {

	printf("%.8lf ms\n",tempo);
	
	for (int i = 0; i < n; i++)
		printf("%.12lf ",resultado[i]);
	printf("\n");
	
	for (int i = 0; i < n; i++)
		printf("%.12lf ",residuo[i]);
	printf("\n\n\n");
}

// Libera a memória usada por um vetor (DEBUG).
void destroi_vetor(double *v) {

	free(v);
}

// Libera a memória usada por uma matriz (DEBUG).
void destroi_matriz(double **m, int n) {

	for(int i = 0; i < n; i++){
		free(m[i]);
	}
	free(m);
}

// Libera a memória usada por um sistema linear, uma matriz(m) e um vetor(v). 
void destroi_sl(double **m, double *v, int n) {

	for(int i = 0; i < n; i++)
		free(m[i]);
	
	free(m);
	free(v);
}

// Libera a memória utilizada por um silstema linear (m,v) e dois vetore.
void destroi_tudo(double **m, double *v, double *residuo, double *resultado, int n) {

	destroi_sl(m,v,n);
	destroi_vetor(residuo);
	destroi_vetor(resultado);
}

// Imprime uma matriz (DEBUG).
void imprime_matriz(double **m, int n) {
	
	printf("matriz:\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%lf ",m[i][j]);
			printf("\n");
		}
}

/*void main(){
	double **m, **mx;
	double *v, *vx, *residuo, *resultado;
	int n;

	le_sl(&m,&v,&n);
	criacopia_sl(m,&mx,v,&vx,n);
	criacopia_vetor(v,&residuo,n);
	criacopia_vetor(v,&resultado,n);

	//imprimir copia do Sistem linear
	printf("Copia do sistema linear:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%lf ",mx[i][j]);
		printf("%lf\n",vx[i]);
	}
	
	imprimeresultado(vx,v,0,n);
	destroi_sl(mx,vx,n);
	destroi_tudo(m,v,residuo,resultado,n);
}*/