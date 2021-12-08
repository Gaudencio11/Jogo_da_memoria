#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Jogador.h"
#include "DateAndTime.h"

const int addValueMonth = 1;
const int addValueYear = 1900;

FILE *pont_arq;


 void verificarAberturaDeArquivos( FILE *ponteiroDoArquivo){
    if (ponteiroDoArquivo == NULL){
          printf("Erro ao tentar abrir o arquivo!");
          exit(1);
    }
 }

 void checarGravacaoDeDados(int result){
   if( result == EOF){
       printf("\nErro ao tentar gravar os dados! \n");

   }else{
        printf("\nDados gravados com sucesso. \n");
     }

 }

 void imprimirDadosDoArquivo(char textoDoArquivo[], FILE *ponteiroDoArquivo){
    while(fgets(textoDoArquivo, 255, ponteiroDoArquivo) != NULL){
         printf("%s", textoDoArquivo);
    }
 }

void escreverDadosNoArquivoDeRanking(struct Jogador jogador,struct tm *dataEHora){

   int result;
   pont_arq = fopen("rankingGame.txt", "a");

   verificarAberturaDeArquivos(pont_arq);

  //Gravando strings no arquivo
    result = fprintf(pont_arq,"Jogador:%s\t%ipts\t salvo em: %i/%i/%i\t as:%i:%i:%i\n",jogador.nomeDoJogador,
                                                           jogador.pontuacaoDoJogador,
                                                           dataEHora->tm_mday,
                                                           dataEHora->tm_mon + addValueMonth,
                                                           dataEHora->tm_year + addValueYear,
                                                           dataEHora->tm_hour,
                                                           dataEHora->tm_min,
                                                           dataEHora->tm_sec);

   checarGravacaoDeDados(result);

   fclose(pont_arq);
}

void lerDadosDoArquivosDeRanking(){

  char textoASerLidoDoArquivo[255];

  //abrindo o arquivo_frase em modo "somente leitura"
  pont_arq = fopen("rankingGame.txt", "r");

  imprimirDadosDoArquivo(textoASerLidoDoArquivo,pont_arq);

  fclose(pont_arq);

  getch();

}

void salvarNomeEPontuacaoNoRanking(char nomeDoJogador [], int pontuacaoDoJogador){
    if(nomeDoJogador[0] != '\0'){
        struct Jogador newJogador = factoryGamer(nomeDoJogador,pontuacaoDoJogador);
        struct tm *data_hora_atual;
        data_hora_atual = getDateTimeCurrent();
        escreverDadosNoArquivoDeRanking(newJogador,data_hora_atual);

    }else{
        printf("Insira os dados");
    }

}


