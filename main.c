//Código de um jogo interativo chamado Tétris emplementado em C,para uso no console (terminal de comando).

//Para executar:
    // start .\programa.exe

// Autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019


#include "tetris.h"

//Parte principal do programa, responsavel por implementar e chamar as funçoes auxiliares
int main() {

    char matrix [ROWS][COLUMNS];
    int posI, posJ;

    //inicializando posição do personagem
    posI = ROWS/2;
    posJ = COLUMNS/2;

    //inicializando a matriz
    init(matrix);

    while(1){

        system("cls");

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posJ < COLUMNS) posJ++;
        
    }

    system("pause");


    return 0;
}
