//Código de um jogo interativo chamado Tétris emplementado em C para uso no console (terminal de comando)

//Para executar:
    // start .\programa.exe

// autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019


//Trabalha apenas funções do programa

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//configurações das dimensões da matriz principal do jogo
#define COLUMNS 30
#define ROWS 60

//configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100
#define TECLA_AA 65
#define TECLA_DD 68
#define TECLA_ESPACO 32

//Defines de orientação das peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_RIGHT 4

// Criação de tipos de peças
#define TIPO_L 1
#define TIPO_L_R 2 // L REVERSO
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 // Z REVERSO 
#define TIPO_O 6  // QUADRADO
#define TIPO_I 7

// CONFIGURAÇÕES DE LAYOUT
#define PIXEL 219
#define EMPTY 32 

//Estrutura padrão de componentes (STRUCT) tamanho peças
typedef struct{
    int i;  // POSIÇÃO NAS LINHAS DA MATRIZ
    int j;  // POSIÇÃO NAS COLUNAS DA MATRIZ
    int orientacao;  // ORIENTAÇÃO DAS PEÇAS
    int tipo; // TIPO DE PEÇAS (7 POSSIVEIS)
    int width; // LARGURA DA PEÇA
    int height; // ALTURA DA PEÇA


}Bloco;

/* 
    Inicializa a matriz principal com 'espaços vazios'
*/

void init (char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteudo da matriz principal na tela do computador
*/

void printMatrix(char matrix[ROWS][COLUMNS]);

// Desenhar uma BARRA usando o simbolo de caractere ASCII passando por parâmetro
void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo);

  
