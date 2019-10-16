//Código de um jogo interativo chamado Tétris emplementado em C,para uso no console (terminal de comando).

//Para executar:
    // start .\programa.exe

// Autora: Heloiza Batista Girarducci da Silva. Data: 28/08/2019


#include "tetris.h"
#include "display.h"
#define DEBUG 1

//Parte principal do programa, responsável por implementar e chamar as funções auxiliares
int main() {

    char matrix [ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;

    //inicializando posição do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_LEFT;
    tijolo.width = 5; //largura
    tijolo.height = 1; //altura

    //inicializando a matriz (espaço vazio)
    init(matrix);

    //apagar (esconder) o cursor da tela

    ShowConsoleCursor(0);
    system("cls");

    //Animação do jogo
    while(keypressed != ESC){ 

        gotoxy(0,0);

        #if DEBUG == 1 
            printf("@ = (%d, %d)\n", tijolo.i, tijolo.j);
            printf("dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif

        //posicionar @ na tela
        drawBar(matrix, tijolo, PIXEL);
        
        //mostra a matriz na tela
        printMatrix(matrix);

        //faz a posição anterior do @ apagar
        drawBar(matrix, tijolo, EMPTY);
                
        //faz a posição da @ ir para o lado direito
        if(tijolo.i < (ROWS-1)) tijolo.i++;
            
        //lendo teclas
        keypressed = 0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch(); //vai utilizar o teclado de direita e esquerda de SETAS

        switch(keypressed){
            // Aqui dois cases juntos estão realizando a mesma função uma para a direita e outra para a esquerda
            case TECLA_AA: //Maiusculo
            case TECLA_A: //vai mover a @ para a esquerda (usa a tecla 'a') o numero 97 é da tabela ASCII
            case LEFT: 
                if((tijolo.j - (tijolo.width/2)) > 0) tijolo.j--; //vai mover a @ para a esquerda (usa a tecla 'seta esquerda <-') o numero 75 é da tabela ASCII
            break;
            case TECLA_DD:  //Maiusculo
            case TECLA_D: //vai mover a @ para a direita (usa a tecla 'd') o numero 100 é da tabela ASCII
            case RIGHT: 
                if((tijolo.j + (tijolo.width/2)) < (COLUMNS-1)) tijolo.j++;  //vai mover a @ para a direita (usa a tecla 'seta direita ->') o numero 77 é da tabela ASCII
            break;
            //Usando espaço para trocar ORIENTAÇÃO (deitado em pé)
            case TECLA_ESPACO:
                if(tijolo.orientacao== ORIENTACAO_RIGHT)
                    tijolo.orientacao = ORIENTACAO_UP;
                else
                    tijolo.orientacao++;

                // Inverte as dimensões do tijolo
                int aux = tijolo.width;
                tijolo.width = tijolo.height;
                tijolo.height = aux;

                // Resolvendo BUG de PEÇA ATRAVESSANDO A FRONTEIRA
                if(tijolo.j < (tijolo.width/2))
                    tijolo.j = tijolo.width/2;
                else if (tijolo.j > COLUMNS - (tijolo.width/2)-1) //DIREITA
                    tijolo.j = COLUMNS - (tijolo.width/2) -1; //Direita
        }

    }

    system("pause");


    return 0;
}
