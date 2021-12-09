#include <stdio.h>


int opcaoMenu(int opcaoEscolhida){

    switch(opcaoEscolhida){

    case 1:
        return opcaoEscolhida;
    break;

    case 2:
        printf("\n\nTecle ENTER para sair\n\n");
        lerDadosDoArquivosDeRanking();
        return 2;
    break;

    case 3:
        exibirCreditos();
        return 2;
    break;

    case 4:
        exit(0);
    break;

    default :
        return 0;

    }
}


void exibirMenuPrincipal(){
  printf("Menu principal:\n\n 1- Jogar\n 2- Ranking\n 3- Creditos\n 4- Sair\n\nSua escolha:  ");
}


void exibirCreditos(){

    printf("Creditos:\n\n\n\n     Joycevania Salvino\n      Josemilson Lopes\n       Matheus Ramos\n       Marcos Novais\n\n"); // mostra todas as vezes os creditos do jogo

	printf("\n  Copyright: Todos os direitos reservados.\n\n\n\n");   // kkkkkkkkk
	sleep(5);
}
