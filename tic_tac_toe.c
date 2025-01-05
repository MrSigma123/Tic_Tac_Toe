/* tic_tac_toe.c -- console version of Tic Tac Toe game */
/* 
  Project design:
  
  TODO:
  - generate the gaming grid
  - implement engine for CPU
  - implement two players mode
    let the user to decide to play X or O (or choose randomly)
  - add counting the score (wins by X and O)
*/

#include <stdio.h>
#include "tic_tac_toe_functions.h"

int main() {
    char board[3][3];
    int player = 1;
    int winner = 0;
    int move_count = 0;

    initialize_board(board);

    while (winner == 0 && move_count < 9) {
        display_board(board);
        printf("Player %d's turn. Enter row and column (0-2): ", player);
        int row, col;
        scanf("%d %d", &row, &col);

        if (make_move(board, row, col, player)) {
            move_count++;
            winner = check_winner(board);
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    display_board(board);
    if (winner) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
