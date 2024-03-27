#include "eg.h"
#include "sl.h"

void retrosub(double **m,double *v,double **resultado,int n){
	
	for(int i = n-1; i >= 0; --i) {
		*resultado[i] = v[i];
		for (int j = i+1; j < n; ++j)
			*resultado[i] -= m[i][j] * resultado[j];
		*resultado[i] /= m[i][i];
	}
}

unsigned int encontra_max(double **m,int i,int n){
	double max = m[i][i];
	for(int j = i; j < n; j++){
		if(m[i][j]>max)
			max=m[i][j];
	}
	return max;
}

void troca_linha(double ***m,double **v,int i,unsigned int pivo){
	
}

void eliminacao_gauss(double ***m,double **v,int n){

	for (int i = 0; i < n; ++i) {
			unsigned int pivo = encontra_max(*m,i,n);
			if(i!=pivo)
			troca_linha(*m,*v,i,pivo);

			for(int k = i+1; k < n; k++) {
				double c = *m[k][i] / *m[i][i];
				*m[k][i] = 0.0;
				for (int j = i+1; i < n; ++j)
					*m[j][i] -= *m[i][j] * c;
				*v[k] -= *v[i] * c;
			}
		}	
}

void eg(double **m,double *v,double **resultado,double **residuo,int n){

}