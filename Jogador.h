#include <stdio.h>
#include <string.h>
#ifndef JOGADOR_H
#define JOGADOR_H
struct Jogador{
    char nomeDoJogador[20];
    int pontuacaoDoJogador;

};
struct Jogador factoryGamer(char nomeDoJogador [], int pontuacaoDoJogador){
    struct Jogador newJogador;
    strcpy(newJogador.nomeDoJogador,nomeDoJogador);
    newJogador.pontuacaoDoJogador = pontuacaoDoJogador;

   return newJogador;
};

#endif // JOGADOR_H


