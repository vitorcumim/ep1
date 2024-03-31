#include <stdio.h>
#include "gs.h"
#include "eg.h"
#include "slinout.h"
#include "utils.h"

int main() {
	double **m, **mx; 
	double *v, *vx, *resultado, *residuo;
	int *n, it = 0; 
	
	le_sl(&m,&v,&n);
	
	criacopia_sl(m,&mx,v,&vx,n);							// Faz uma copia do sistema linear (m,v) no sistema linear auxiliar (mx,vx).
	//ALOCAR OS VETORES resultado e residuo;(podemos alocar dentro da EG);
	//calcular tempo
	eg(mx,vx,&resultado,&residuo,n);
	//retorna tempo
	printf("EG clássico:\n");
	imprimeresultado(resultado,residuo,tempo,n);
	destroi_sl(mx,vx,n); 									// Libera a memória usada pelo sistema linear auxiliar.

	criacopia_sl(m,&mx,v,&vx,n);							// Faz uma copia do sistema linear (m,v) no sistema linear auxiliar (mx,vx).
	//calcular tempo
	gs(mx,vx,resultado,residuo,n,it);
	//retornar tempo
	printf("GS clássico  [ %d iterações ]:\n",it);
	imprimeresultado(resultado,residuo,tempo,n);
	destroi_sl(mx,vx,n); 									// Libera a memória usada pelo sistema linear auxiliar.
	
	criacopia_sl(m,&mx,v,&vx,n);							// Faz uma copia do sistema linear (m,v) no sistema linear auxiliar (mx,vx).
	//calcular tempo
	eg3(mx,vx,resultado,residuo,n);
	//retornar tempo
	printf("EG 3-diagonal:\n");
	imprimeresultado(resultado,residuo,tempo,n);
	destroi_sl(mx,vx,n); 									// Libera a memória usada pelo sistema linear auxiliar.

	criacopia_sl(m,&mx,v,&vx,n);							// Faz uma copia do sistema linear (m,v) no sistema linear auxiliar (mx,vx).
	//calcular tempo
	gs3(mx,vx,resultado,residuo,n,it);
	//retornar tempo
	printf("GS 3-diagonal [ %d iterações ]:\n",it);
	imprimeresultado(resultado,residuo,tempo,n);

	destroitudo(m,mx,v,vx,residuo,resultado,n);         	// Libera toda memória antes de finalizar o programa.

	return 0;
}