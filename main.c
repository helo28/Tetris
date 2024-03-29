//Código de um jogo interativo chamado Tétris emplementado em C,para uso no console (terminal de comando).

//Para executar:
    // start .\programa.exe

// Autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019

#include "tetris.h"
#include "display.h"

//Parte principal do programa, responsável por implementar e chamar as funções auxiliares
int main() {

    char matrix [ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;

    //apagar (esconder) o cursor da tela
    ShowConsoleCursor(0);
    system("cls");
    
    //posição inicial do personagem
    initBar(&tijolo);

    //inicializando a matriz (espaço vazio)
    init(matrix);

    //Animação do jogo
    while(keypressed != ESC){ 

        gotoxy(0,0);

        #if DEBUG == 1 
            printf("@ = (%d, %d)\n", tijolo.i, tijolo.j);
            printf("dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif

        //posicionar @ na tela - desenha
        drawBar(matrix, tijolo, PIXEL);
        
        //mostra a matriz na tela
        printMatrix(matrix);

        //faz a posição anterior do @ apagar
        if(!collisionBar(matrix, tijolo, UNCHECK_SIDE, NONE)) {
            drawBar(matrix, tijolo, EMPTY);

        //faz a posição da @ ir para o lado direito andar para baixo
        if(tijolo.i < (ROWS-1)) tijolo.i++;

     }else{
         initBar(&tijolo);
     }
            
        //lendo teclas
        keypressed = 0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch(); //vai utilizar o teclado de direita e esquerda de SETAS

        switch(keypressed){
            // Aqui dois cases juntos estão realizando a mesma função uma para a direita e outra para a esquerda
            case TECLA_AA: //Maiusculo
            case TECLA_A: //vai mover a @ para a esquerda (usa a tecla 'a') o numero 97 é da tabela ASCII
            case LEFT: 
                   if(!collisionBar(matrix, tijolo, CHECK_SIDE, LEFT))
                        tijolo.j--; //vai mover a @ para a esquerda (usa a tecla 'seta esquerda <-') o numero 75 é da tabela ASCII
            break;
            case TECLA_DD:  //Maiusculo
            case TECLA_D: //vai mover a @ para a direita (usa a tecla 'd') o numero 100 é da tabela ASCII
            case RIGHT: 
                    if(!collisionBar(matrix, tijolo, CHECK_SIDE, RIGHT))
                tijolo.j++;  //vai mover a @ para a direita (usa a tecla 'seta direita ->') o numero 77 é da tabela ASCII
            break;

            //Usando espaço para trocar ORIENTAÇÃO (deitado em pé)
            case TECLA_ESPACO:
                rotate(&tijolo);
            break;
        }
    }

    system("pause");


    return 0;
}
