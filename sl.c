#include "sl.h"

void aloca_matriz(double **m,int n) {

	m = (double **)malloc(n * sizeof(double *));
	for(int i = 0; i < n; i++){
		m[i] = (double *)malloc(n * sizeof(double));
	}
}

void aloca_vetor(double *v,int n) {

	v = malloc(sizeof(double) * n);
}

void le_sl(double **m,double *v,int *n) {

	scanf("%d",n);
	getchar();
	
	aloca_matriz(m,*n);
	aloca_vetor(v,*n);

	if(&m == NULL)
		return;
	for (int i = 0; i < *n ; i++) {
		if(&m[i] != NULL){
			for (int j = 0; j < *n; j++) {
				scanf("%lf",&m[i][j]);
			}
		}
		scanf("%lf",&v[i]);
	}
}

void criacopia_matriz(double **m,double **mx,int n) {

	aloca_matriz(mx,n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			mx[i][j] = m[i][j];
	}
}

void criacopia_vetor(double *v,double *vx,int n) {

	aloca_vetor(vx,n);
	for (int i = 0; i < n; i++){
			vx[i] = v[i];
	}
}

void imprimeresultado(double *resultado,double *residuo,double tempo,int n) {

	printf("%lf ms",tempo);
	
	for(int i = 0; i < n; i++){
		printf("%lf ",resultado[i]);
	}

	printf("\n");

	for(int i = 0; i < n; i++){
		printf("%lf ",residuo[i]);
	}
}

void destroi_matriz(double **m,int n){

	for(int i = 0; i < n; i++){
		free(m[i]);
	}
	free(m);
}

void destroi_vetor(double *v,int n) {

	free(v);
}

void destroi_tudo(double **m,double **mx,double *v,double *vx,double *residuo,double *resultado,int n) {

	destroi_matriz(m,n);
	destroi_matriz(mx,n);
	destroi_vetor(v,n);
	destroi_vetor(vx,n);
	destroi_vetor(residuo,n);
	destroi_vetor(resultado,n);
}

void main(){
	double **m, **mx;
	double *v, *vx, *residuo, *resultado;
	int n;


	le_sl(m,v,&n);
	criacopia_matriz(m,mx,n);
	criacopia_vetor(v,vx,n);
	criacopia_vetor(v,residuo,n);
	criacopia_vetor(v,resultado,n);
	
	//imprimir copia
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			printf("%lf ",mx[i][j]);
		printf("\n");
	}
	
	imprimeresultado(vx,v,0,n);
	destroi_tudo(m,mx,v,vx,residuo,resultado,n);
}