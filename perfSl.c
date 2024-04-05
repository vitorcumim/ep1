/*	Nome: Rafael Urbanek Laurentino
*	GRR: 20224381
*	Nome: Vitor Lorenzo Cumim
*	GRR: 20224757 
*/

#include <likwid.h>
#include "sl.h"
#include "eg.h"
#include "gs.h"
#include "eg3d.h"
#include "gs3d.h"

int main() {
	double **m;						// Define duas variáveis, uma matriz(m) e um vetor(v) para compor um sistema linear.
	double *v;
	int n; 							// Define uma variável para o grau so sitema;
	
	LIKWID_MARKER_INIT;

	le_sl(&m,&v,&n);				// Passa por referência o sistema linear, aloca espaço na memória e lê logo em seguida.
	
	eg(m,v,n);						// Executa a eliminação de gauss para o sistema linear.
	printf("\n");

	gs(m,v,n);						// Executa o método de gauss seidel para um sistema linear.
	printf("\n");

	eg3d(m,v,n);					// Executa a eliminação de gauss para uma sistema tridiagonal.
	printf("\n");
	
	gs3d(m,v,n);					// Executa o método de gauss seidel para um sistema tridiagoal.

	destroi_sl(m,v,n);  			// Libera a memória usada pelo sistema linear lido.

	LIKWID_MARKER_CLOSE;       	

	return 0;
}