#ifndef TIC_TAC_TOE_FUNCTIONS_H
#define TIC_TAC_TOE_FUNCTIONS_H

void initialize_board(char board[3][3]);
void display_board(char board[3][3]);
int make_move(char board[3][3], int row, int col, int player);
int check_winner(char board[3][3]);

#endif // TIC_TAC_TOE_FUNCTIONS_H
