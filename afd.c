#include <stdio.h>
#include <string.h>
#define MAX 1000

int main() {
    int estado = 1;
    int i=0;

    printf("Digite o texto a ser analisado\n");
    char entrada[MAX];
    fgets(entrada, MAX, stdin);
    int tamanhoEntrada = strlen(entrada);

    char lexemaAceito[100]= "";
    int tamanhoAtualLexemaAceito = 0;

    char caractereAtual;

    while(estado!=5 && i<tamanhoEntrada) {
        caractereAtual = entrada[i];
        printf("Caractere de entrada: %c \n", caractereAtual);
        printf("Comecou no estado: %i \n", estado);
        switch(estado) {
            case 1:
                switch(caractereAtual){
                    case '/':
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        estado=2;
                        break;
                    default :
                        estado=10;
                        break;
                }
                break;
            case 2:
                switch(caractereAtual){
                    case '*':
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        estado = 3;
                        break;
                    default :
                        estado = 10;
                        break;
                }
                break;
            case 3:
                switch(caractereAtual){
                    case '*':
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        estado = 4;
                        break;
                    default :
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        break;
                }
                break;
            case 4: 
                switch(caractereAtual){
                    case '/':
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        estado = 5;
                        break;
                    case '*' :
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        estado = 4;
                        break;
                    default :
                        lexemaAceito[tamanhoAtualLexemaAceito] = caractereAtual;
                        tamanhoAtualLexemaAceito++;
                        estado = 3;
                        break;
                }
                break;
            case 10:
                tamanhoAtualLexemaAceito = 0;
                estado = 1;
                break;
        }
        //permance no caractere de entrada que deu erro para ser pego na prox rodada no case 10 
        if(estado!=10){
            i++;
        }
        printf("saiu no estado: %i \n\n", estado);
    }
    if(estado==5) {
        printf("\n\nPrimeiro Lexema Aceito: %s \n",lexemaAceito);
    }
    else {
        printf("\nNenhum token foi reconhecido");
    }
return 0;
}
