#include <stdio.h>
#include "gs.h"
#include "eg.h"
#include "slinout.h"
#include "utils.h"

int main() {
	double **m;
	double *v;
	int *n, it = 0; 
	
	le_sl(&m,&v,&n);										// Lê o sitema linear.
	
	eg(m,v,n);												// Executa a eliminação de gauss para o sistema linear.

	gs(mx,vx,resultado,residuo,n,it);						//NAO IMPLEMENTADO
	
	eg3d(m,v,n);											// Executa a eliminação de gauss para uma matriz tridiagonal.
	



	criacopia_sl(m,&mx,v,&vx,n);							
	//calcular tempo
	gs3(mx,vx,resultado,residuo,n,it);
	//retornar tempo
	printf("GS 3-diagonal [ %d iterações ]:\n",it);			//NAO IMPLEMENTADO
	imprimeresultado(resultado,residuo,tempo,n);

	destroi_sl(m,v,n);         	

	return 0;
}