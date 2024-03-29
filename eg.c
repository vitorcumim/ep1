#include "sl.h"
#include "eg.h"

void retrosub(double **m, double *v, double *resultado, int n) {
	
	for(int i = n-1; i >= 0; --i) {
		resultado[i] = v[i];
		for (int j = i+1; j < n; ++j)
			resultado[i] -= m[i][j] * resultado[j];
		resultado[i] /= m[i][i];
	}
}

unsigned int encontra_max(double **m, int i, int n) {
	double max = m[i][i];
	int linha = i;
	
	for(int j = i; j < n; j++){
		if(m[i][j]>max){
			max=m[i][j];
			linha = j;
		}
	}
	return linha;
}

void troca_linha(double **m, double *v, int i, unsigned int pivo, int n) {
	double aux_m, aux_v;

	for (int j = 0; j < n; j++) {
        aux_m = m[i][j];
        m[i][j] = m[pivo][j];
        m[pivo][j] = aux_m;
    }
	aux_v = v[i];
	v[i] = v[pivo];
	v[pivo] = aux_v;
}

void eliminacao_gauss(double **m, double *v, int n) {

	for (int i = 0; i < n; ++i) {
			unsigned int pivo = encontra_max(m,i,n);
			if(i!=pivo)
			troca_linha(m,v,i,pivo,n);

			for(int k = i+1; k < n; k++) {
				double c = m[k][i] / m[i][i];
				m[k][i] = 0.0;
				for (int j = i+1; j < n; ++j){
					m[k][j] -= m[i][j] * c;
				}
				v[k] -= v[i] * c;
			}
		}	
}

void eg(double **m, double *v, double *resultado, double *residuo, int n) {

	eliminacao_gauss(m,v,n);
	retrosub(m,v,resultado,n);
}

/*int main() {
	double **m, *v ,tempo=0.0; 
	double **mx, *vx ,*resultado ,*residuo;
	int n, it = 0; 
	
	le_sl(&m,&v,&n);
	criacopia_matriz(m,&mx,n);
	criacopia_vetor(v,&vx,n);
	
	resultado = aloca_vetor(n);
	residuo = aloca_vetor(n);
	memset(residuo,0,n*sizeof(double));
	
	//calcular tempo
	eg(mx,vx,resultado,residuo,n);
	//retorna tempo
	
	printf("EG clássico:\n");
	imprimeresultado(resultado,residuo,tempo,n);
	destroi_tudo(m,mx,v,vx,residuo,resultado,n);
	return 0;
}*/