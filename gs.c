#include "gs.h"

double calculaErro(double *resultado, double *ex_resultado, int n) {
	double *diff, maior;

	maior = 0.0;
	diff = aloca_vetor(n);

	for (int i = 0; i < n; i++) {
		diff[i] = ABS(resultado[i] - ex_resultado[i]);
		if (maior < diff[i])
			maior = diff[i];
	}

	copia_vetor(resultado,ex_resultado,n);
	destroi_vetor(diff);
	return maior;
}

void gaussSeidel(double **m, double *v, double *resultado, uint n, int *it) {
	double erro = 1 + TOL, s, *ex_resultado;
	int j;

	ex_resultado = aloca_vetor(n);
	memset(ex_resultado,0,n*sizeof(double));

	while (erro > TOL && (*it) < 50) {
		for (int i = 0; i < n; ++i) {
			for (s = 0, j = 0; j < n; ++j){
				if (i != j)
					s += (m[i][j] * resultado[j]);
			}
			resultado[i] = (v[i] - s) / m[i][i];
		}
		erro = calculaErro(resultado,ex_resultado,n);
		printf("ERRO:%lf\n",erro); 			//debug
		(*it) ++;
	}
	
	destroi_vetor(ex_resultado);
}

void gs(double **m, double *v, int n) { 
	double *resultado, *residuo;
	double tempo;
	int it = 0;

	resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(residuo,0,n*sizeof(double));
	memset(resultado,0,n*sizeof(double));

	tempo = timestamp();
	gaussSeidel(m,v,resultado,n,&it);
	calculaResiduo(m,v,resultado,residuo,n);
	tempo = timestamp() - tempo;
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