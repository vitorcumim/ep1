#include "gs.h"

double calculaErro(double *resultado,double *ex_resultado,int n) {
	double *diff,maior;

	maior=0.0;

	diff = aloca_vetor(n);

	for(int i=0;i<n;i++){
		diff[i]=resultado[i]- ex_resultado[i];
		if(maior<diff[i]){
			maior=diff[i];
		}
		printf("%lf ",diff[i]);
	}

	printf("\n");

	copia_vetor(resultado,ex_resultado,n); //ver se da pra fazer melhor

	destroi_vetor(diff);
	
	return maior;
}

void gaussSeidel (double **m,double *v, double *resultado, uint n,int *it) {
	double erro = 0, *ex_resultado;
	int j, s;

	ex_resultado = aloca_vetor(n);
	memset(ex_resultado,0,n*sizeof(double));

	printf("erro:%lf,it:%d\n",erro,*it);

	while (erro < TOL && *it < 50) {
		printf("entra while\n"); 
		for (int i=0; i < n; ++i) {
			for (s=0, j=0; j < n; ++j)
				if (i != j) s += m[ i ][ j ] * resultado[ j ];
			resultado[ i ] = (v[i] - s) / m[ i ][ i ];
			erro = calculaErro(resultado,ex_resultado,n);
			printf("erro:%lf\n",erro);
			*it++;
			printf("resultado[i]:%lf\n",resultado[i]);
		}

	}
	destroi_vetor(ex_resultado);
}

void gs(double **m, double *v, int n) { 
	double *resultado, *residuo;
	double tempo = 0.0;
	int it=0;

	resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(residuo,0,n*sizeof(double));
	memset(resultado,0,n*sizeof(double));

	//tempo inicio
	gaussSeidel(m,v,resultado,n,&it);
	//tempo fim
	printf("GS clássico  [ %d iterações ]:\n",it);
	imprimeresultado(resultado,residuo,tempo,n);
	destroi_vetor(residuo);
	destroi_vetor(resultado);
}

int main() {
	double **m;
	double *v;
	int n; 
	
	le_sl(&m,&v,&n);
	
	gs(m,v,n);
	
	destroi_sl(m,v,n);
	return 0;
}