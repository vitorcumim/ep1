#include <stdio.h>
#include "gs.h"
#include "eg.h"
#include "slinout.h"
#include "utils.h"

int main() {
	double **m, *v; 
	double **mx, *v;
	int *n, it = 0; 
	
	le_sl(&m,&v,&n);
	criacopia_matriz(m,mx,n);
	criacopia_vetor(v,vx,n);
	//calcular tempo
	eg(mx,vx,resultado,residuo,n);
	//retorna tempo
	printf("EG clássico:\n");
	imprimeresultado(resultado,residuo,tempo,n);

	criacopia_matriz(m,mx,n);
	criacopia_vetor(v,vx,n);
	//calcular tempo
	gs(mx,vx,resultado,residuo,n,it);
	//retornar tempo
	printf("GS clássico  [ %d iterações ]:\n",it);
	imprimeresultado(resultado,residuo,tempo,n);

	criacopia_matriz(m,mx,n);
	criacopia_vetor(v,vx,n);
	//calcular tempo
	eg3(mx,vx,resultado,residuo,n);
	//retornar tempo
	printf("EG 3-diagonal:\n");
	imprimeresultado(resultado,residuo,tempo,n);

	criacopia_matriz(m,mx,n);
	criacopia_vetor(v,vx,n);
	//calcular tempo
	gs3(mx,vx,resultado,residuo,n,it);
	//retornar tempo
	printf("GS 3-diagonal [ %d iterações ]:\n",it);
	imprimeresultado(resultado,residuo,tempo,n);

	destroitudo(m,mx,v,vx,residuo,resultado,n);

	return 0;
}









}