#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define NUM_BOMBS 15
void boardToBoardGame(int board[TAM][TAM], char boardGame[TAM][TAM]){
    for(int i =0; i < TAM; i++){
        for(int j = 0; j < TAM ; j++){
            if(board[i][j] == 0){
                boardGame[i][j] = '_';
            }
            else if(board[i][j] == 10){
                boardGame[i][j] = '*';
            }
            else{
                boardGame[i][j] = board[i][j]+'0';
            }
        }
    }

}
void createBoard(int board[TAM][TAM]){
    for(int i =0; i < TAM; i++){
        for(int j = 0; j < TAM ; j++){
            board[i][j] = 0;
        }
    }
}
void bombBoard(int board[TAM][TAM]){
    createBoard(board);
    srand(time(NULL));
    int countBombs = 0;
    int i = rand() % 10;
    int j = rand() % 10;
    while(countBombs < NUM_BOMBS){
        if(board[i][j] == 0){
            board[i][j] = 10;
            countBombs++;
        }
        i = rand() % 10;
        j = rand() % 10;
    }
}
void printBoard(int board[TAM][TAM]){
    for(int i =0; i < TAM; i++){
            printf("\n");
        for(int j = 0; j < TAM ; j++){
                printf("%5d", board[i][j]);
        }
    }
}
int position(int i, int j){
    int numOfBombs = 0;
    if(i == 0 && j ==0){
        return 0;
    }

    else if(i == 0 && j == (TAM -1)){
        return 1;
    }

    else if(i == (TAM -1) && j == 0 ){//canto inf esquerdo
       return 2;
    }

    else if(i == (TAM -1) && j == (TAM -1)){//canto inf direito
       return 3;
    }

    else if(i == 0 && j > 0 && j < (TAM -1)){//linha sup
       return 4;
    }
    else if(i == (TAM - 1) && j > 0 && j < (TAM -1)){//linha inf
       return 5;
    }

    else if(j == 0 && i > 0 && i < (TAM -1)){//col esquedd
       return 6;
    }

    else if(j == (TAM - 1)&& i > 0 && i < (TAM -1)){//coluna direita
        return 7;
    }
    else{ //meio
        return 8;
    }
}
int countOfBombs(int board[TAM][TAM], int i, int j){
    int numOfBombs = 0;
    switch(position(i, j)){
        case 0:// 0,0
            if(board[i+1][j]==10){
                numOfBombs++;
            }
            if(board[i][j+1]==10){
                numOfBombs++;
            }
            if(board[i+1][j+1]==10){
                numOfBombs++;
            }
            break;
        case 1:
            if(board[i+1][j]==10){
                numOfBombs++;
            }
            if(board[i][j-1]==10){
                numOfBombs++;
            }
            if(board[i+1][j-1]==10){
                numOfBombs++;
            }
            break;
        case 2:
            if(board[i-1][j]==10){
                numOfBombs++;
            }
            if(board[i][j+1]==10){
                numOfBombs++;
            }
            if(board[i-1][j+1]==10){
                numOfBombs++;
            }
            break;
        case 3:
            if(board[i-1][j]==10){
                numOfBombs++;
            }
            if(board[i][j-1]==10){
                numOfBombs++;
            }
            if(board[i-1][j-1]==10){
                numOfBombs++;
            }
            break;
        case 4:
            if(board[i+1][j]==10){
                numOfBombs++;
            }
            if(board[i+1][j+1]==10){
                numOfBombs++;
            }
            if(board[i+1][j-1]==10){
                numOfBombs++;
            }
            if(board[i][j+1]==10){
                numOfBombs++;
            }
            if(board[i][j-1]==10){
                numOfBombs++;
            }
            break;
        case 5:
            if(board[i-1][j]==10){
                numOfBombs++;
            }
            if(board[i-1][j+1]==10){
                numOfBombs++;
            }
            if(board[i-1][j-1]==10){
                numOfBombs++;
            }
            if(board[i][j+1]==10){
                numOfBombs++;
            }
            if(board[i][j-1]==10){
                numOfBombs++;
            }
            break;
        case 6:
            if(board[i+1][j]==10){
                numOfBombs++;
            }
            if(board[i-1][j+1]==10){
                numOfBombs++;
            }
            if(board[i+1][j+1]==10){
                numOfBombs++;
            }
            if(board[i-1][j]==10){
                numOfBombs++;
            }
            if(board[i][j+1]==10){
                numOfBombs++;
            }
            break;
        case 7:
            if(board[i][j-1]==10){
                numOfBombs++;
            }
            if(board[i-1][j]==10){
                numOfBombs++;
            }
            if(board[i+1][j]==10){
                numOfBombs++;
            }
            if(board[i-1][j-1]==10){
                numOfBombs++;
            }
            if(board[i+1][j-1]==10){
                numOfBombs++;
            }
            break;
        default:
            if(board[i][j-1]==10){
                numOfBombs++;
            }
            if(board[i][j+1]==10){
                numOfBombs++;
            }
            if(board[i+1][j]==10){
                numOfBombs++;
            }
            if(board[i-1][j]==10){
                numOfBombs++;
            }
            if(board[i+1][j-1]==10){
                numOfBombs++;
            }
            if(board[i+1][j+1]==10){
                numOfBombs++;
            }
            if(board[i-1][j+1]==10){
                numOfBombs++;
            }
            if(board[i-1][j-1]==10){
                numOfBombs++;
            }
        }
    return numOfBombs;
}
void gameBoard(int board[TAM][TAM]){
    for(int i =0; i < TAM; i++){
        for(int j = 0; j < TAM ; j++){
            if(board[i][j] == 0){
                board[i][j] = countOfBombs(board, i, j);
            }
        }
    }
}
void createBoardGame(char boardGame[TAM][TAM]){
    for(int i =0; i < TAM; i++){
        for(int j = 0; j < TAM ; j++){
            boardGame[i][j] = '-';
        }
    }
}
void printBoardGame(char boardGame[TAM][TAM]){
    for(int i =0; i < TAM; i++){
        printf("\n");
        if(i < 9){
            printf(" %d# ", i+1);
        }
        else{
            printf("%d# ", i+1);
        }
        for(int j = 0; j < TAM ; j++){
            printf("%5c", boardGame[i][j]);
        }
    }
    printf("\n");
    printf("\n        #    #    #    #    #    #    #    #    #    #    ");
    printf("\n    ");
    for(int j = 0; j < TAM ; j++){
        printf("%5d", j+1);
    }
}
int isAPossibleMove(int board[TAM][TAM], int i, int j, char boardGame[TAM][TAM]){
    if(i < 0 || i >= TAM || j < 0 || j>= TAM){
        printf("Spot out of board ");
        return 0;
    }
    else if(boardGame[i][j]!= '-'){
        printf("Spot already open ");
        return 0;
    }
    else{
        return 1;
    }
}
int isABomb(int board[TAM][TAM], int i, int j){
    if(board[i][j] == 10){
       return 1;
    }
    else{
       return 0;
    }
}
void showBoard(int i, int j, int board[TAM][TAM], char boardGame[TAM][TAM]){
   switch(position(i, j)){
        case 0:
            boardGame[i+1][j] = board[i+1][j]+'0';
            boardGame[i][j+1] = board[i][j+1]+'0';
            boardGame[i+1][j+1] = board[i+1][j+1]+'0';
            break;
        case 1:
            boardGame[i+1][j] = board[i+1][j]+'0';
            boardGame[i][j-1] = board[i][j-1]+'0';
            boardGame[i+1][j-1] = board[i+1][j-1]+'0';
            break;
        case 2:
            boardGame[i-1][j] = board[i-1][j]+'0';
            boardGame[i][j+1] = board[i][j+1]+'0';
            boardGame[i-1][j+1] = board[i-1][j+1]+'0';
            break;
        case 3:
            boardGame[i-1][j] = board[i-1][j]+'0';

            boardGame[i][j-1] = board[i][j-1]+'0';

            boardGame[i-1][j-1] = board[i-1][j-1]+'0';

            break;
        case 4:
            boardGame[i+1][j] = board[i+1][j]+'0';

            boardGame[i+1][j+1] = board[i+1][j+1]+'0';

            boardGame[i+1][j-1] = board[i+1][j-1]+'0';

            boardGame[i][j+1] = board[i][j+1]+'0';

            boardGame[i][j-1] = board[i][j-1]+'0';

            break;
        case 5:
            boardGame[i-1][j] = board[i-1][j]+'0';

            boardGame[i-1][j+1] = board[i-1][j+1]+'0';

            boardGame[i-1][j-1] = board[i-1][j-1]+'0';

            boardGame[i][j+1] = board[i][j+1]+'0';

            boardGame[i][j-1] = board[i][j-1]+'0';

            break;
        case 6:
            boardGame[i+1][j] = board[i+1][j]+'0';

            boardGame[i-1][j+1] = board[i-1][j+1]+'0';

            boardGame[i+1][j+1] = board[i+1][j+1]+'0';

            boardGame[i-1][j] = board[i-1][j]+'0';

            boardGame[i][j+1] = board[i][j+1]+'0';

            break;
        case 7:
            boardGame[i][j-1] = board[i][j-1]+'0';

            boardGame[i-1][j] = board[i-1][j]+'0';

            boardGame[i+1][j] = board[i+1][j]+'0';

            boardGame[i-1][j-1] = board[i-1][j-1]+'0';

            boardGame[i+1][j-1] = board[i+1][j-1]+'0';

            break;
        default:
            boardGame[i][j-1] = board[i][j-1]+'0';

            boardGame[i][j+1] = board[i][j+1]+'0';

            boardGame[i+1][j] = board[i+1][j]+'0';

            boardGame[i-1][j] = board[i-1][j]+'0';

            boardGame[i+1][j-1] = board[i+1][j-1]+'0';

            boardGame[i+1][j+1] = board[i+1][j+1]+'0';

            boardGame[i-1][j+1] = board[i-1][j+1]+'0';

            boardGame[i-1][j-1] = board[i-1][j-1]+'0';
        }
}
int makeMove(int board[TAM][TAM], char boardGame[TAM][TAM], int i, int j, int op, int *flags){
   if(op == 0){
        boardGame[i][j] ='*';
        *flags = *flags +1;
        return 1;
   }
   else if(isABomb(board, i, j) == 1){
        return 0;
   }
   else if(board[i][j] == 0){
       boardGame[i][j] = board[i][j]+'0';
       showBoard(i, j, board, boardGame);
       return 1;
   }
   else{
       boardGame[i][j] = board[i][j]+'0';
       return 1;
   }
}
void receivePlay(int *i, int *j, int *op){
    int x, y;
    printf("\n SHOW :1 - MARK :0 ->");
    scanf("%d", op);
    printf("\n DIGITE LINHA 1-10 ->");
    scanf("%d", &x);
    printf("\n DIGITE COLUNA 1-10 ->");
    scanf("%d", &y);
    *i = x-1;
    *j = y-1;
}
int winGame(char boardGame[TAM][TAM]){
    for(int i =0; i < TAM; i++){
        for(int j = 0; j < TAM ; j++){
            if(boardGame[i][j] == '-'){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int board[TAM][TAM];
    char boardGame[TAM][TAM];
    int i, j, esc, op, flags = 0;
    //criando board
    bombBoard(board);
    gameBoard(board);
    //criate player board
    createBoardGame(boardGame);
    //printando player board
    printf("\nFLAGS: %d", flags);
    printf("\n");
    printBoardGame(boardGame);
    //recebendo jogada
    do{
    receivePlay(&i, &j, &op);
    }while(isAPossibleMove(board, i, j, boardGame) == 0);
    // game
    while(makeMove(board, boardGame, i, j, op, &flags) == 1 && winGame(boardGame)!= 1){
        printf("\n FLAGS: %d", flags);
        printBoardGame(boardGame);
        do{
           receivePlay(&i, &j, &op);
        }while(isAPossibleMove(board, i, j, boardGame)== 0);
        system("cls");
    }
    if(makeMove(board, boardGame, i, j, op, &flags) == 0){
            printf("\n BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!");
            boardToBoardGame(board, boardGame);
            boardGame[i][j] = 'X';
            printf("\n YOU LOSE");
            printBoardGame(boardGame);
            scanf("%d", &esc);
        }
    else{
        if(winGame(boardGame) == 1){
            printf("\n YOU WIIN");
            printBoardGame(boardGame);
            scanf("%d", &esc);
        }
    }
    return 0;
}
