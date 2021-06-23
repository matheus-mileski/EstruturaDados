#include "ex03.h"

int potencia(int x, int y){
	
	if(y>0){
		x=x*potencia(x,y-1);
	}else{
		return 1;
	}
	
	return x;
	
}

int main() {
	
	int x,y;
	
	printf("Informe o valor de x (base):");
	scanf("%i",&x);
	printf("Informe o valor de y (expoente):");
	scanf("%i",&y);
	
	printf("\n%i^%i = %i\n",x,y,potencia(x,y));
	
	return 0;
}
