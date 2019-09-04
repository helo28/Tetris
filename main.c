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
    posI = ROWS/2;
    posJ = COLUMNS/2;

    //inicializando a matriz
    init(matrix);

    //apagar (esconder) o cursor da tela

    ShowConsoleCursor(0);
    system("cls");

    while(1){

        gotoxy(0,0);

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' '; 
        
        if(posJ < COLUMNS) posJ++;
        
    }

    system("pause");


    return 0;
}
