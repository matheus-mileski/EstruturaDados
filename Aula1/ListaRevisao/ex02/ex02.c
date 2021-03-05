#include "ex02.h"

int main() {

    char nome_arquivo[100];
    int n_linhas=0;
    char c;

    printf("Informe o nome do arquivo de entrada: ");
    scanf("%[^\n]",&nome_arquivo);

    FILE *entrada;
    FILE *saida;

    printf("%s", nome_arquivo);

    entrada = fopen(nome_arquivo,"r");
    // Windows
    saida = fopen("D:\\mathe\\Documents\\GITHUB\\EstruturaDados\\Aula1\\ListaRevisao\\ex02\\ex02_output.txt","w");
    // Linux
    // saida = fopen("saida_ex02.txt","w");

    if(entrada == NULL || saida == NULL){
        printf("\n\nErro ao abrir arquivo\nEncerrando programa\n");
        exit(1);
    }

    while(1){

        c = fgetc(entrada);

        if(c == '\n'){
            n_linhas++;
            fputc(c,saida);
        }else if(c == EOF){
            n_linhas++;
            break;
        }else if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){

            fputc('*',saida);
        }else{
            fputc(c,saida);
        }
    }

    printf("\n\nO arquivo de entrada possui %i linha(s)\n\n",n_linhas);

    fclose(entrada);
    fclose(saida);

    return 0;
}
