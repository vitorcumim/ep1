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

// Lê um sistema linear. Uma matrix n*n e um vetor n. 
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

// Copia o vetor v para o vetor vx (DEBUG).
void criacopia_vetor(double *v, double **vx, int n) {
	*vx = aloca_vetor(n);

	for (int i = 0; i < n; i++){
			(*vx)[i] = v[i];
	}
}

// Copia a matriz m para a matriz mx (DEBUG).
void criacopia_matriz(double **m, double ***mx, int n) {
	*mx = aloca_matriz(n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			(*mx)[i][j] = m[i][j];
	}
}

// Copia o sistema linear (m,v) para o sistema linear (mx,vx).
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

// Imprime os vetores resultado, resíduo e o tempo.
void imprimeresultado(double *resultado, double *residuo, double tempo, int n) {

	printf("%.8lf ms\n",tempo);
	
	for (int i = 0; i < n; i++)
		printf("%.12lf ",resultado[i]);
	printf("\n");
	
	for (int i = 0; i < n; i++)
		printf("%.12lf ",residuo[i]);
	printf("\n");
}

// Libera a memória usada por um vetor (DEBUG).
void destroi_vetor(double *v, int n) {

	free(v);
}

// Libera a memória usada por uma matriz (DEBUG).
void destroi_matriz(double **m, int n) {

	for(int i = 0; i < n; i++){
		free(m[i]);
	}
	free(m);
}

// Libera a memória usada por um sistema linear (uma matriz e um vetor).
void destroi_sl(double **m, double *v, int n) {

	for(int i = 0; i < n; i++)
		free(m[i]);
	
	free(m);
	free(v);
}

// Libera toda a memória utilizada para cada método.
void destroi_tudo(double **m, double *v, double *residuo, double *resultado, int n) {

	destroi_sl(m,v,n);
	destroi_vetor(residuo,n);
	destroi_vetor(resultado,n);
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