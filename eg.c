//	Nome: Rafael Urbanek Laurentino
// 	GRR: 20224381
// 	Nome: Vitor Lorenzo Cumim
// 	GRR: 20224757

#include "eg.h"
#include <likwid.h>

// Realiza a retrosubstituição em uma matriz triangularizada.
void retrosub(double **m, double *v, double *resultado, int n) {
	
	for (int i = n-1; i >= 0; --i) {
		resultado[i] = v[i];
		for (int j = i+1; j < n; ++j)
			resultado[i] -= m[i][j] * resultado[j];
		resultado[i] /= m[i][i];
	}
}

// Encontra o maior número da coluna para realizar o pivoteamento.
unsigned int encontra_max(double **m, int i, int n) {
	double max = m[i][i];				// define o pivo como maior.
	int linha = i;
	
	for (int k = i; k < n; k++) {		// percorre toda a coluna.
		if (m[k][i] > max) {			// caso seja econtrado um numero maior que max ele o atualiza e guarda a linha de ocorrência.
			max = m[k][i];				
			linha = k;
		}
	}
	return linha;						// retorna a linha que deve ser trocada com a linha do pivo.
}

// Troca duas linha de uma matriz.
void troca_linha(double **m, double *v, int i, uint pivo, int n) {
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

// Realiza o pivoteamento e a triangularizção da matriz.
void triangulariza(double **m, double *v, int n) {

	for (int i = 0; i < n; ++i) {
			uint pivo = encontra_max(m,i,n);
			if(i != pivo)									// Pivoteamento.
				troca_linha(m,v,i,pivo,n);

			for(int k = i+1; k < n; k++) {
				double c = m[k][i] / m[i][i];
				m[k][i] = 0.0;								// Triangularização.
				for (int j = i+1; j < n; ++j) {
					m[k][j] -= m[i][j] * c;
				}
				v[k] -= v[i] * c;
			}
		}	
}

// Função principal utilizada na main(perfSl). Triangulariza a matriz, em seguida faz a retrosubstituição e imprime os resultados.
void eg(double **m, double *v, int n) {
	double **mx; 
	double *vx, *resultado, *residuo;
	double tempo;

	resultado = aloca_vetor(n);								// Aloca memória para o vetor de resultados.
	residuo = aloca_vetor(n);								// Aloca memória para o vetor de resíduos.
	memset(resultado,0,n*sizeof(double));					// Preenche o vetor de resultado com zeros.
	memset(residuo,0,n*sizeof(double));						// Preenche o vetor de reíduos com zeros.

	criacopia_sl(m,&mx,v,&vx,n);							// Faz uma copia do sistema linear (m,v) no sistema linear auxiliar (mx,vx).
	LIKWID_MARKER_START("EG_clássico");
	tempo = timestamp();
	triangulariza(mx,vx,n);
	retrosub(mx,vx,resultado,n);
	tempo = timestamp() - tempo;
	LIKWID_MARKER_STOP("EG_clássico");
	calculaResiduo(m,v,resultado,residuo,n);				// Calcula os resíduos
	printf("EG clássico:\n");
	imprimeresultado(resultado,residuo,tempo,n);			// Imprime os resultados.
	destroi_tudo(mx,vx,resultado,residuo,n);				// Libera toda memória utilizada.
}

/*int main() {
	double **m;
	double *v;
	int n; 
	
	le_sl(&m,&v,&n);
	
	eg(m,v,n);
	
	destroi_sl(m,v,n);
	return 0;
}*/