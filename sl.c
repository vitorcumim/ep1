#include "sl.h"

double** aloca_matriz(int n) {
	double** m;

	m = malloc(sizeof(double *) * n);
	for(int i = 0; i < n; i++){
		m[i] = malloc(sizeof(double) * n);
	}
	return m;
}

double* aloca_vetor(int n) {
	double* v;

	v = malloc(sizeof(double) * n);
	return v;
}

void le_sl(double ***m,double **v,int *n) {

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

void criacopia_matriz(double **m,double ***mx,int n) {

	*mx = aloca_matriz(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			(*mx)[i][j] = m[i][j];
	}
}

void criacopia_vetor(double *v,double **vx,int n) {

	*vx = aloca_vetor(n);
	for (int i = 0; i < n; i++){
			(*vx)[i] = v[i];
	}
}

void imprimeresultado(double *resultado,double *residuo,double tempo,int n) {

	printf("tempo: %lf ms\n",tempo);
	
	printf("resultado:\n");
	for(int i = 0; i < n; i++){
		printf("%lf ",resultado[i]);
	}

	printf("\n");

	printf("residuo:\n");
	for(int i = 0; i < n; i++){
		printf("%lf ",residuo[i]);
	}
	printf("\n");
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


	le_sl(&m,&v,&n);
	criacopia_matriz(m,&mx,n);
	criacopia_vetor(v,&vx,n);
	criacopia_vetor(v,&residuo,n);
	criacopia_vetor(v,&resultado,n);
	
	printf("VETOR:\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			printf("%lf ",mx[i][j]);
		printf("\n");
	}
	
	imprimeresultado(vx,v,0,n);
	destroi_tudo(m,mx,v,vx,residuo,resultado,n);
}