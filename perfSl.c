#include "sl.h"
#include "eg.h"
#include "gs.h"
#include "eg3d.h"
#include "gs3d.h"

int main() {
	double **m;
	double *v;
	int n; 
	
	le_sl(&m,&v,&n);										// Lê o sitema linear.
	
	eg(m,v,n);												// Executa a eliminação de gauss para o sistema linear.

	gs(m,v,n);												// Executa o método de gauss seidel para um sistema linear.
	
	eg3d(m,v,n);											// Executa a eliminação de gauss para uma sistema tridiagonal.
	
	gs3d(m,v,n);											// Executa o método de gauss seidel para um sistema tridiagoal.

	destroi_sl(m,v,n);         	

	return 0;
}