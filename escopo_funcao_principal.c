#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include "ValidateInput.h"
#include "saveRankingGame.h"


//Função para gerar uma matriz aletória
int *matriz_aleatoria(){
    //Cria 4 vetores com tamanho int
    int **matriz = malloc(sizeof(int*)*4);

    int sorteados[8]={2, 3, 4, 5, 6, 7, 8, 9};
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

//Criei apenas para simular a estrutura que vocês criaram para o jogador
typedef struct jogador{
    int tipo, pontuacao;
}JOGADOR;

#define time_t ST_HORA = time(NULL);

//Função para gerar o layout da matriz a ser exibida.
//Recebe a matriz, o tipo 1- para a matriz dos valores e 0 - para o verso, repetir para saber se repete ou não
int exibir_cartas(int **cartas[4][4], int tipo, int repetir){
    //indica que tipo é, virado para cima ou para baixo

    int linha, coluna, index;
    int **ponteiro_da_matriz = cartas;
    if(repetir == 1 && tipo ==1 || tipo == 0 ){
        printf("\n");
        if (tipo == 1){
            printf("Veja atentamente! Irá se apagar em 5 segundos\n");
            sleep(2);
        }else{
            printf("Cartas viradas para baixo:\n");
        }

        printf("\n");
        for(linha=0; linha<4; linha++){
            if(linha ==0){
                printf("    1  2  3  4 \n");
                printf("    -  -  -  -  \n");
            }else{
                printf("\n");
            }
            printf(" %i|", linha+1);
            for(coluna=0; coluna<4; coluna++){
                printf(" %i ", ponteiro_da_matriz[linha][coluna]);
            }
        }
        if (tipo==1){
            sleep(5);
            system("cls");
        }
    }

}

//Serve para conferir os valores digitados
//0 para tudo ok, 1 para posicao impossível e 2 para número escrito já selecionado
int conferir_se_poscao_possivel_e_valor_naoZero(int linha, int coluna, int **matriz_conferir_zero[4][4]){

    int **pont_matriz = matriz_conferir_zero;

    if (linha <0 || linha>4 || coluna<0 || coluna>4){
        return 1;
    }else if(pont_matriz[linha][coluna] == 0){
        return 2;
    }
    return 0;


}

//Função principal
int main(void){
    setlocale(LC_ALL,"Portuguese");

    int linha, coluna, index, apoio, repetir = 1;
    int **matriz_original= matriz_aleatoria(), **cartas_para_baixo = malloc(sizeof(int*)*4);
    int primeiro_linha,primeiro_coluna,segundo_linha,segundo_coluna;
    char primeira_linha_digitada, primeira_coluna_digitada;
    char segunda_linha_digitada, segunda_coluna_digitada;
    char nomeDoJogador1 [20];
    char nomeDoJogador2 [20];

    int jogadorOnePontuacao;
    int jogadoTwoPontuacao;

    JOGADOR jogador1, jogador2;
    jogador1.tipo =1;
    jogador2.tipo = 2;
    jogador1.pontuacao = jogador2.pontuacao = 0;

    //Alocando os vetores da matriz
    for(index=0;index<4; index++){
        cartas_para_baixo[index] = malloc(sizeof(int)*4);
    }
    //preenchendo essa matriz
    for(linha=0; linha<4; linha++){
        for(coluna=0; coluna<4; coluna++){
            cartas_para_baixo[linha][coluna] = 00;
        }
    }

    do{
         printf("Digite o nome do jogador 1: ");
         scanf("%s",nomeDoJogador1);

        printf("Digite o nome do jogador 2: ");
        scanf("%s",nomeDoJogador2);
    }while(nomeDoJogador1[0] == '\0' && nomeDoJogador2[0] == '\0');


    //Esse while representa toda a partida
    while(jogador1.pontuacao + jogador2.pontuacao < 8){

        //um for desse representa cada rodada
        for(index=1; index<3; index++){

            if(jogador1.pontuacao + jogador2.pontuacao == 8){
                break;

            }

            printf("\n>> Vez do jogador %i <<\n", index);

            exibir_cartas(matriz_original, 1, repetir);
            exibir_cartas(cartas_para_baixo, 0, repetir);
            printf("\n");
            //primeira posição:
            while(1){
                printf("\nJogador %i Digite a posição de uma carta: \n", index);
                printf("linha:");
                scanf(" %c", &primeira_linha_digitada);
                printf("coluna:");
                scanf(" %c", &primeira_coluna_digitada);

                int linhaSeForDoTipoNumerico = verificarSeAEntradaNumerica(primeira_linha_digitada);
                int colunaSeForDoTipoNumerico = verificarSeAEntradaNumerica(primeira_coluna_digitada);

                primeiro_linha = converterEntradaDoJogadorParaTipoNumerico(linhaSeForDoTipoNumerico,primeira_linha_digitada);
                primeiro_coluna = converterEntradaDoJogadorParaTipoNumerico(colunaSeForDoTipoNumerico,primeira_coluna_digitada);
                //Se retornar 1 o usuário digitou uma posição impossível
                //Se retornar 2 o número já foi escolhido
                //se retornar 0 está ok, e ele quebra o laço
                apoio = conferir_se_poscao_possivel_e_valor_naoZero(primeiro_linha-1, primeiro_coluna-1, matriz_original);
                if(apoio == 1){
                    printf("\nEssa posição não existe! \nDigite Novamente\n");
                }else if(apoio == 2){
                    printf("\nEssa carta já foi escolhida! \nDigite Novamente\n");
                }else if(apoio==0){
                    break;
                }
            }

            printf("\n>> Número da Carta %i x %i : %i <<\n", primeiro_linha, primeiro_coluna, matriz_original[primeiro_linha-1][primeiro_coluna-1]);
            printf("---------------------------------- \n");
            sleep(3);

            //segunda posição:
            while(1){
                printf("Digite a posição da carta igual à anterior: \n");
                printf("linha:");
                scanf(" %c", &segunda_linha_digitada);
                printf("coluna:");
                scanf(" %c", &segunda_coluna_digitada);

                int linhaSeForDoTipoNumerico = verificarSeAEntradaNumerica(segunda_linha_digitada);

                int colunaSeForDoTipoNumerico = verificarSeAEntradaNumerica(segunda_coluna_digitada);

                segundo_linha = converterEntradaDoJogadorParaTipoNumerico(linhaSeForDoTipoNumerico,segunda_linha_digitada);

                segundo_coluna = converterEntradaDoJogadorParaTipoNumerico(colunaSeForDoTipoNumerico,segunda_coluna_digitada);

                //Se retornar 1 o usuário digitou uma posição impossível
                //Se retornar 2 o número já foi escolhido
                //se as posições forem iguais ele reclama que a mesma carta foi ecolhida
                //se retornar 0 está ok, e ele quebra o laço
                apoio = conferir_se_poscao_possivel_e_valor_naoZero(segundo_linha-1, segundo_coluna-1, matriz_original);
                if(apoio == 1){
                    printf("\nEssa posição não existe! \nDigite Novamente\n");
                }else if(apoio == 2){
                    printf("\nEssa carta já foi escolhida! \nDigite Novamente\n");
                }else if (segundo_linha == primeiro_linha && segundo_coluna==primeiro_coluna){
                    printf("\n !!!Você escolheu a mesma carta!!! \Tente Novamente\n");
                    printf("\n");
                }else if(apoio==0){
                    break;
                }
            }

            printf("\n>> Número da Carta %i x %i : %i << \n", segundo_linha, segundo_coluna, matriz_original[segundo_linha-1][segundo_coluna-1]);
            printf("---------------------------------- \n");
            sleep(3);

            // Conferir se os números digitados são iguais e adicionar a pontuação a cada jogador
            system("cls");
            if(matriz_original[segundo_linha-1][segundo_coluna-1] == matriz_original[primeiro_linha-1][primeiro_coluna-1]){
                printf("......................................... \n");
                printf("Você Acertou!! \n");
                //Caso Jogador 1
                if(index == 1){
                    jogador1.pontuacao++;
                    jogadorOnePontuacao++;
                    printf("-------------- \n");
                    printf("Pontuação de jogador %i é: %i\n", jogador1.tipo, jogador1.pontuacao);
                    printf("-------------- \n");
                    printf("Pontuação de jogador %i é: %i\n", jogador2.tipo, jogador2.pontuacao);
                    printf("......................................... \n");
                    sleep(4);
                    system("cls");

                    //atribuindo os valores da outra matriz para a nova (virando as cartas nessa matriz)
                    cartas_para_baixo[primeiro_linha-1][primeiro_coluna-1] = matriz_original[primeiro_linha-1][primeiro_coluna-1];
                    cartas_para_baixo[segundo_linha-1][segundo_coluna-1] = matriz_original[segundo_linha-1][segundo_coluna-1];

                    //Virando as cartas nessa matriz
                    matriz_original[primeiro_linha-1][primeiro_coluna-1] = matriz_original[segundo_linha-1][segundo_coluna-1] = 0;

                    //Repete a vez do jogador(index--) e evita que ele veja novamente as cartas(repetir=0)
                    repetir = 0;
                    index --;

                //Caso Jogador 2
                }else{
                    jogador2.pontuacao++;
                    printf("----------------------\n");
                    printf("Pontuação de jogador %i é: %i\n", jogador1.tipo, jogador1.pontuacao);
                    printf("Pontuação de jogador %i é: %i\n", jogador2.tipo, jogador2.pontuacao);
                    printf("---------------------- \n ");
                    sleep(4);
                    system("cls");

                    //atribuindo os valores da outra matriz para a nova (virando as cartas nessa matriz)
                    cartas_para_baixo[primeiro_linha-1][primeiro_coluna-1] = matriz_original[primeiro_linha-1][primeiro_coluna-1];
                    cartas_para_baixo[segundo_linha-1][segundo_coluna-1] = matriz_original[segundo_linha-1][segundo_coluna-1];

                    //Virando as cartas nessa matriz
                    matriz_original[primeiro_linha-1][primeiro_coluna-1] = matriz_original[segundo_linha-1][segundo_coluna-1] = 0;

                    //Repete a vez do jogador(index--) e evita que ele veja novamente as cartas(repetir=0)
                    repetir = 0;
                    index--;
                }
            }else{
                printf("jogador %i : Você Errou\n", index);
                printf("----------------------\n");
                printf("Pontuação de jogador %i é: %i\n", jogador1.tipo, jogador1.pontuacao);
                printf("Pontuação de jogador %i é: %i\n", jogador2.tipo, jogador2.pontuacao);
                printf("---------------------- \n");
                printf("vv Vez do próximo jodador vv\n");
                sleep(5);
                system("cls");
                //permite que as cartas sejam mostradas novamente
                repetir = 1;
            }
        }
    }

    if(jogador1.pontuacao > jogador2.pontuacao){
        printf("\nO jogador 1 Ganhou!");
    }else if (jogador1.pontuacao < jogador2.pontuacao){
        printf("\nO jogador 1 Ganhou!");
    }else{
        printf("\nO jogador 1 Ganhou!");
    }
    salvarNomeEPontuacaoNoRanking(nomeDoJogador1,jogador1.pontuacao);
    salvarNomeEPontuacaoNoRanking(nomeDoJogador2,jogador2.pontuacao);
    return 0;
}
