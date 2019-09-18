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
    int keypressed=0;

    //inicializando posição do personagem
    posI = 0;
    posJ = COLUMNS/2;

    //inicializando a matriz (espaço vazio)
    init(matrix);

    //apagar (esconder) o cursor da tela

    ShowConsoleCursor(0);
    system("cls");

    //Animação do jogo
    while(keypressed != ESC){

        gotoxy(0,0);

        //posicionar @ na tela
        matrix[posI][posJ] = '@';

        //mostra a matriz na tela
        printMatrix(matrix);

        //faz a posição anterior do @ apagar
        matrix[posI][posJ] = ' '; 
        
        //faz a posição da @ ir para o lado direito
        if(posI < (ROWS-1)) posI++;
            
        //lendo teclas
        keypressed = 0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch(); //vai utilizar o teclado de direita e esquerda de SETAS

        switch(keypressed){
            // Aqui dois cases juntos estão realizando a mesma função uma para a direita e outra para a esquerda
            case TECLA_A: //vai mover a @ para a esquerda (usa a tecla 'a') o numero 97 é da tabela ASCII
            case LEFT: 
                if(posJ > 0) posJ--; //vai mover a @ para a esquerda (usa a tecla 'seta esquerda <-') o numero 75 é da tabela ASCII
            break;  
            case TECLA_D: //vai mover a @ para a direita (usa a tecla 'd') o numero 100 é da tabela ASCII
            case RIGHT: 
                if(posJ < (COLUMNS-1)) posJ++;  //vai mover a @ para a direita (usa a tecla 'seta direita ->') o numero 77 é da tabela ASCII
            break;
        }

    }

    system("pause");


    return 0;
}
