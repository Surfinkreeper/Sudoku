#include "header.h"

int main() {
    int board1[BOARD_SIZE][BOARD_SIZE] = {
        {BLANK, BLANK, BLANK, 8, BLANK, BLANK, BLANK, BLANK, 9},
        {BLANK, 1, 9, BLANK, BLANK, 5, 8, 3, BLANK},
        {BLANK, 4, 3, BLANK, 1, BLANK, BLANK, BLANK, 7},
        {4, BLANK, BLANK, 1, 5, BLANK, BLANK, BLANK, 3},
        {BLANK, BLANK, 2, 7, BLANK, 4, BLANK, 1, BLANK},
        {BLANK, 8, BLANK, BLANK, 9, BLANK, 6, BLANK, BLANK},
        {BLANK, 7, BLANK, BLANK, BLANK, 6, 3, BLANK, BLANK},
        {BLANK, 3, BLANK, BLANK, 7, BLANK, BLANK, 8, BLANK},
        {9, BLANK, 4, 5, BLANK, BLANK, BLANK, BLANK, 1}
    };

    if(!solveSudoku(board1, 0)) {
        cout << "No solution!";
    }

    return 0;   
}