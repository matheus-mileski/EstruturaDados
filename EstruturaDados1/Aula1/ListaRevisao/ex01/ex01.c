#include "ex01.h"

void total_minutos(int* h,int* m){

    int total;
    printf("Informe o total de minutos: ");
    scanf("%i",&total);

    *h = total/60;
    *m = total%60;
}

int main()
{

    int horas, minutos;

    total_minutos(&horas,&minutos);

    printf("\n%ih%02i\n",horas,minutos);

    return 0;
}