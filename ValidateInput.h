#include<stdio.h>
#include <stdlib.h>

int converterEntradaDoJogadorParaTipoNumerico(int tipoNumerico, char caracterDigitado[]){
      if(tipoNumerico == 1){
            int value;
            int valorConvertido = atoi(caracterDigitado);
         return valorConvertido;
      }
}

int verificarSeAEntradaNumerica(char caracterDigitado[]){
    int i;

    for(i = 0; caracterDigitado != '\0';i++){
        if(caracterDigitado[i] >='0'){
            return 1;
        }
    }
     return 0;
}

