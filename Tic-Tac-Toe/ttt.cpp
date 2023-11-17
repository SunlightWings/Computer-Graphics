#include <bits/stdc++.h>  
using namespace std;  

#define AI 1  
#define PLAYER 2  
#define BOARD_SIZE 3
#define AI_MOVE 'O'  
#define PLAYER_MOVE 'X'  

void displayBoard(char board[][BOARD_SIZE])  
{  
    printf("\n\n");  
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);  
    printf("\t\t\t--------------\n");  
    printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);  
    printf("\t\t\t--------------\n");  
    printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);  
    return;  
}  

void showInstructions()  
{  
    printf("\t\t\t Tic-Tac-Toe\n\n");  
    printf("Choose a cell numbered from 1 to 9 as below and play\n\n");  
    printf("\t\t\t 1 | 2 | 3 \n");  
    printf("\t\t\t--------------\n");  
    printf("\t\t\t 4 | 5 | 6 \n");  
    printf("\t\t\t--------------\n");  
    printf("\t\t\t 7 | 8 | 9 \n\n");  
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");  
    return;  
}  

void initializeGame(char board[][BOARD_SIZE], int moves[])  
{  
    srand(time(NULL));  
    for (int i = 0; i < BOARD_SIZE; i++)  
    {  
        for (int j = 0; j < BOARD_SIZE; j++)  
            board[i][j] = ' ';  
    }  
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)  
        moves[i] = i;  
    random_shuffle(moves, moves + BOARD_SIZE * BOARD_SIZE);  
    return;  
}  

void announceWinner(int whoseTurn)  
{  
    if (whoseTurn == AI)  
        printf("AI has won\n");  
    else  
        printf("PLAYER has won\n");  
    return;  
}  

bool isRowCrossed(char board[][BOARD_SIZE])  
{  
    for (int i = 0; i < BOARD_SIZE; i++)  
    {  
        if (board[i][0] == board[i][1] &&  
            board[i][1] == board[i][2] &&  
            board[i][0] != ' ')  
            return true;  
    }  
    return false;  
}  

bool isColumnCrossed(char board[][BOARD_SIZE])  
{  
    for (int i = 0; i < BOARD_SIZE; i++)  
    {  
        if (board[0][i] == board[1][i] &&  
            board[1][i] == board[2][i] &&  
            board[0][i] != ' ')  
            return true;  
    }  
    return false;  
}  

bool isDiagonalCrossed(char board[][BOARD_SIZE])  
{  
    if (board[0][0] == board[1][1] &&  
        board[1][1] == board[2][2] &&  
        board[0][0] != ' ')  
        return true;  
    if (board[0][2] == board[1][1] &&  
        board[1][1] == board[2][0] &&  
        board[0][2] != ' ')  
        return true;  
    return false;  
}  

bool isGameOver(char board[][BOARD_SIZE])  
{  
    return (isRowCrossed(board) || isColumnCrossed(board) || isDiagonalCrossed(board));  
}  

void playGame(int whoseTurn)  
{  
    char board[BOARD_SIZE][BOARD_SIZE];  
    int moves[BOARD_SIZE * BOARD_SIZE];  
    initializeGame(board, moves);  
    showInstructions();  
    int moveIndex = 0, x, y;  

    while (isGameOver(board) == false &&  
           moveIndex != BOARD_SIZE * BOARD_SIZE)  
    {  
        if (whoseTurn == AI)  
        {  
            x = moves[moveIndex] / BOARD_SIZE;  
            y = moves[moveIndex] % BOARD_SIZE;  
            board[x][y] = AI_MOVE;  
            printf("AI has put a %c in cell %d\n",  
                   AI_MOVE, moves[moveIndex] + 1);  
            displayBoard(board);  
            moveIndex++;  
            whoseTurn = PLAYER;  
        }  
        else if (whoseTurn == PLAYER)  
        {  
            x = moves[moveIndex] / BOARD_SIZE;  
            y = moves[moveIndex] % BOARD_SIZE;  
            board[x][y] = PLAYER_MOVE;  
            printf("PLAYER has put a %c in cell %d\n",  
                   PLAYER_MOVE, moves[moveIndex] + 1);  
            displayBoard(board);  
            moveIndex++;  
            whoseTurn = AI;  
        }  
    }  

    if (isGameOver(board) == false &&  
        moveIndex == BOARD_SIZE * BOARD_SIZE)  
        printf("It's a draw\n");  
    else  
    {  
        if (whoseTurn == AI)  
            whoseTurn = PLAYER;  
        else if (whoseTurn == PLAYER)  
            whoseTurn = AI;  
        announceWinner(whoseTurn);  
    }  

    return;  
}  

int main()  
{  
    playGame(AI);  
    return 0;  
}


/* 
Output:

Tic-Tac-Toe

Choose a cell numbered from 1 to 9 as below and play

			 1 | 2 | 3 
			--------------
			 4 | 5 | 6 
			--------------
			 7 | 8 | 9 

-	-	-	-	-	-	-	-	-	-

AI has put a O in cell 9|   |   
			--------------
			   |   |   
			--------------
			   |   | O 

PLAYER has put a X in cell 1


			 X |   |   
			--------------
			   |   |   
			--------------
			   |   | O 

AI has put a O in cell 3


			 X |   | O 
			--------------
			   |   |   
			--------------
			   |   | O 

PLAYER has put a X in cell 2


			 X | X | O 
			--------------
			   |   |   
			--------------
			   |   | O 

AI has put a O in cell 8


			 X | X | O 
			--------------
			   |   |   
			--------------
			   | O | O 

PLAYER has put a X in cell 6


			 X | X | O 
			--------------
			   |   | X 
			--------------
			   | O | O 

AI has put a O in cell 4


			 X | X | O 
			--------------
			 O |   | X 
			--------------
			   | O | O 

PLAYER has put a X in cell 7


			 X | X | O 
			--------------
			 O |   | X 
			--------------
			 X | O | O 

AI has put a O in cell 5


			 X | X | O 
			--------------
			 O | O | X 
			--------------
			 X | O | O 

It's a draw
  */
