//Código de um jogo interativo chamado Tétris emplementado em C,para uso no console (terminal de comando).

//Para executar:
    // start .\programa.exe

// Autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019


#include "tetris.h"
#include "display.h"

//Parte principal do programa, responsável por implementar e chamar as funções auxiliares
int main() {

    char matrix [ROWS][COLUMNS];
    int posI, posJ;

    //inicializando posição do personagem
    posI = 0;
    posJ = COLUMNS/2;

    //inicializando a matriz (espaço vazio)
    init(matrix);

    //apagar (esconder) o cursor da tela

    ShowConsoleCursor(0);
    system("cls");

    //Animação do jogo
    while(1){

        gotoxy(0,0);

        //posicionar @ na tela
        matrix[posI][posJ] = '@';

        //mostra a matriz na tela
        printMatrix(matrix);

        //faz a posição anterior do @ apagar
        matrix[posI][posJ] = ' '; 
        
        //faz a posição da @ ir para o lado
        if(posI < (ROWS-1)) posI++;
            
    }

    system("pause");


    return 0;
}
