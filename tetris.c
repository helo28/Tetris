//Código de um jogo interativo chamado Tétris emplementado em C para uso no console (terminal de comando)

//Para executar:
    // start .\programa.exe

// autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019

//Trabalha apenas comandos 

#include "tetris.h"

/* 
    Inicializa a matriz principal com 'espaços vazios'
*/

void init (char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}

void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }

        printf("\n");
    }
}