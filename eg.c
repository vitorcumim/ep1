#include "eg.h"
#include "sl.h"

void retrosub(double **m,double *v,double **resultado,int n){
	
	for(int i = n-1; i >= 0; --i) {
		*resultado[i] = v[i];
		for (int j = i+1; j < n; ++j)
			*resultado[i] -= m[i][j] * *resultado[j];
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
	double *aux_linha,aux_res;

	aux_linha=*m[i];
	aux_res=*v[i];
	*m[i]=*m[pivo];
	*v[i]=*v[pivo];
	*m[pivo]=aux_linha;
	*v[pivo]=aux_res;
}

void eliminacao_gauss(double ***m,double **v,int n){

	for (int i = 0; i < n; ++i) {
			unsigned int pivo = encontra_max(*m,i,n);
			if(i!=pivo)
			troca_linha(m,v,i,pivo);

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

	eliminacao_gauss(&m,&v,n);
	*residuo=aloca_vetor(n);
	memset(*residuo,0,n*sizeof(double));
	*resultado=aloca_vetor(n);
	retrosub(m,v,resultado,n);
}

int main(int argc, char const *argv[])
{
	double **m, *v ,tempo=0.0; 
	double **mx, *vx ,*resultado ,*residuo;
	int *n, it = 0; 
	
	le_sl(&m,&v,n);
	criacopia_matriz(m,&mx,*n);
	criacopia_vetor(v,&vx,*n);
	//calcular tempo
	eg(mx,vx,&resultado,&residuo,*n);
	//retorna tempo
	printf("EG clássico:\n");
	imprimeresultado(resultado,residuo,tempo,*n);
	destroi_matriz(mx,*n);
	destroi_vetor(vx, *n);
	return 0;
}