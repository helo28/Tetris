//Código de um jogo interativo chamado Tétris emplementado em C para uso no console (terminal de comando)

//Para executar:
    // start .\programa.exe

// autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019


//Trabalha apenas funções do programa

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//configurações das dimensões da matriz principal do jogo
#define COLUMNS 60
#define ROWS 25

//configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100
#define TECLA_AA 65
#define TECLA_DD 68

/* 
    Inicializa a matriz principal com 'espaços vazios'
*/

void init (char matrix[ROWS][COLUMNS]);

//Mostra o conteudo da matriz principal na tela do computador

void printMatrix(char matrix[ROWS][COLUMNS]);