#include <stdio.h>
#include <conio.h>
#include <time.h>


int *matriz_aleatoria(){
    //Cria 4 vetores com tamanho int
    int **matriz = malloc(sizeof(int*)*4);

    int sorteados[8]={33, 44, 55, 66, 77, 88, 99, 11};
    int linha, coluna, random_coluna, random_linha, index, x, apoio =0;


    //aloca para cada vetor 4 espaços do tamanho int
    for(index=0;index<4; index++){
        matriz[index] = malloc(sizeof(int)*4);
    }

    //preenche a matriz toda com 0s
    for(linha=0; linha<4; linha++){
        for(coluna=0; coluna<4; coluna++){
            matriz[linha][coluna] = 0;
        }
    }

    srand(time(NULL));
    for(index=0; index<8; index++){
        x=1;
        while(x==1){
            apoio++;
            random_coluna = rand() % 4;
            random_linha = rand()% 4;

            if (matriz[random_linha][random_coluna] == 0){

                matriz[random_linha][random_coluna] = sorteados[index];
                x=2;
            }
        }
        x=1;
        while(x==1){
            apoio++;
            random_coluna = rand() % 4;
            random_linha = rand()% 4;
            if (matriz[random_linha][random_coluna] == 0){

                matriz[random_linha][random_coluna] = sorteados[index];
                x=2;
            }
        }
    }

    return matriz;
}


//apenas a título de teste e exemplificando como chamar a função na main
int main(void){

    int linha, coluna;
    int **matriz = matriz_aleatoria();

    for(linha=0; linha<4; linha++){
        printf("\n");
        for(coluna=0; coluna<4; coluna++){
            printf(" %i ", matriz[linha][coluna]);
        }
    }



    return 0;
}

