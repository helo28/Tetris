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

    /*Mostra o conteudo da matriz principal na tela do computador */

void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

        printf("\t\t\t\t\t");
        //Linha de cima
            for(j=0; j<COLUMNS+2; j++){
                printf("*");
    }

    printf("\n");
    
    //Matriz do jogo

    for(i=0; i<ROWS; i++){
        printf("\t\t\t\t\t*");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }

        printf("*\n");
    }
    
        printf("\t\t\t\t\t");
            //Linha de baixo
            for(j=0; j<COLUMNS+2; j++){
                printf("*");
    }
        printf("\n");
}
 
// Desenhar uma BARRA usando o simbolo de caractere ASCII passando por parâmetro
void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
    // Desenhado orientação em PÉ
    switch(barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP:
            if(barra.i-4>=0) matrix[barra.i-4][barra.j] = simbolo;
            if(barra.i-3>=0) matrix[barra.i-3][barra.j] = simbolo;
            if(barra.i-2>=0) matrix[barra.i-2][barra.j] = simbolo;
            if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
            break; 

        //Desenhado em orientação DEITADO
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT:
            if(barra.j+1>=0) matrix[barra.i][barra.j+1] = simbolo;
            if(barra.j+2>=0) matrix[barra.i][barra.j+2] = simbolo;
            if(barra.j-2>=0) matrix[barra.i][barra.j-2] = simbolo;
            if(barra.j-1>=0) matrix[barra.i][barra.j-1] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
        break;
    }
  }
        
void initBar (Bloco *barra){
    barra->i = 0;
    barra->j = COLUMNS/2;
    barra->tipo = TIPO_I;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width = 5; //largura
    barra->height = 1; //altura

    #if DEBUG == 1
        printf("posI: %d posJ: %d \n", barra->i, barra->j);
        system("pause");
    #endif

}


void rotate(Bloco *bloco){
    if(bloco->orientacao== ORIENTACAO_RIGHT)
        bloco->orientacao = ORIENTACAO_UP;
    else
        bloco->orientacao++;

    // Inverte as dimensões do tijolo
    int aux = bloco->width;
    bloco->width = bloco->height;
    bloco->height = aux;

    // Resolvendo BUG de PEÇA ATRAVESSANDO A FRONTEIRA
    if(bloco->j < (bloco->width/2))
        bloco->j = bloco->width/2;
     else if (bloco->j > COLUMNS - (bloco->width/2)-1) //DIREITA
        bloco->j = COLUMNS - (bloco->width/2) -1; //Direita
}

//Verifica COLISÃO de blocos
int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra, int collideSides, int side){
    int retorno = 0;

        //VERIFICA COLISÃO COM A BASE
        if((barra.i + 1) >= ROWS)
            retorno = 1;

    //Verificando colisão ENTRE PEÇAS
    // verifica a linha de i mais 1 abaixo
    if(matrix[barra.i + 1][barra.j] != EMPTY) // Vendo que Houve colisão  J é a base da peça
        retorno = 1;

    int t2 = barra.width / 2;

    if(matrix[barra.i+1][barra.j + t2] != EMPTY)
        retorno = 1;

    if(matrix[barra.i+1][barra.j + t2] != EMPTY)
        retorno = 1;
        
    return retorno;
}

//Verifica COLISÃO de BARRAS
int collisionBar(char matrix[ROWS][COLUMNS], Bloco barra){
    int retorno = 0;

        //VERIFICA COLISÃO COM A BASE
        if((barra.i + 1) >= ROWS)
            retorno = 1;

    //Verificando colisão da Base da Barra com outras peças
    // verifica a linha de i mais 1 abaixo
    if(matrix[barra.i + 1][barra.j] != EMPTY) // Vendo que Houve colisão  J é a base da peça
        retorno = 1;

    //Colisão com Base Horizontal
    int t2 = barra.width / 2;

    if(matrix[barra.i+1][barra.j + t2] != EMPTY)
        retorno = 1;

    if(matrix[barra.i+1][barra.j + t2] != EMPTY)
        retorno = 1;
    
    //Colisão Lateral Horizontal   t2 é a distância entre o ponto principal da peça (o seu centro) até o seu final
    if(collideSides==CHECK_SIDE && (barra.orientacao == ORIENTACAO_LEFT || barra.orientacao == ORIENTACAO_RIGHT)){
        if(side==RIGHT && matrix[barra.i][barra.j + t2 + 1] != EMPTY)
            retorno = 1;
        if(side==RIGHT && barra.j + t2 + 1 >= COLUMNS)
            retorno = 1;

        if(side==LEFT && matrix[barra.i][barra.j - t2 - 1] != EMPTY)
            retorno = 1;
        if(side==LEFT && barra.j - t2 - 1 < 0)
            retorno = 1;
    }

    //Colisão lateral Vertical
    if(collideSides==CHECK_SIDE && (barra.orientacao == ORIENTACAO_UP || barra.orientacao == ORIENTACAO_DOWN)) {
        int i;
        for(i=0; i<barra.height; i++){
            //Verificando se ocorreu colisão lateral com restos de outras peças
            if(side==RIGHT && matrix[barra.i-i][barra.j + 1] != EMPTY)
                retorno = 1;

            if(side=LEFT && matrix[barra.i-i][barra.j - 1] != EMPTY)
                retorno = 1;
        }

        if(side==RIGHT && barra.j + 1 >= COLUMNS )
            retorno = 1;
        
        if(side==LEFT && barra.j)
    }
    
    return retorno;
}