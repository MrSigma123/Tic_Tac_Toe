/* tic_tac_toe_functions.c */

#include "tic_tac_toe_functions.h"
#include <stdio.h>

void initialize_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

int make_move(char board[3][3], int row, int col, int player) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        return 0;
    }
    board[row][col] = (player == 1) ? 'X' : 'O';
    return 1;
}

int check_winner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return (board[i][0] == 'X' || board[0][i] == 'X') ? 1 : 2;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return (board[1][1] == 'X') ? 1 : 2;
    }
    return 0;
}
