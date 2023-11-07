#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

const int BOARD_SIZE = 9;
const int BLANK = 0;

bool solveSudoku(int board[][BOARD_SIZE], int cell);
bool isValid(int board[][BOARD_SIZE], int row, int col, int num);
void printBoard(int board[][BOARD_SIZE]);

void printBoard(int board[][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++) {
            if(board[r][c] == BLANK) {
                cout << "   ";
            }
            else {
                cout << " " << board[r][c] << " ";
            }
        }
        cout << endl;
    }
}

bool solveSudoku(int board[][BOARD_SIZE], int cell) {

    int row = cell/9;
    int col = cell%9;

    if( cell == 81 ) {
        printBoard(board);
        return true;
    }

    if(board[row][col] != BLANK) {
        return solveSudoku(board, cell + 1 );
    }

    for(int i = 1; i <= 9; i++) {
        if(isValid(board, row, col, i)) {
            board[row][col] = i;
            
            if(solveSudoku(board, cell + 1)) {
                return true;
            }
            
            //Backtrack if the next cell returns false
            board[row][col] = BLANK;
        }
    }

    return false;
}

bool isValid(int board[][BOARD_SIZE], int row, int col, int num) {

    //check row/column
    for(int i = 0; i < BOARD_SIZE; i++ ) {
        //check row
        if(board[i][col] == num) {
            return false;
        }
        //check column
        if(board[row][i] == num) {
            return false;
        }
    }

    //check box
    int bigRow = row/3*3;
    int bigCol = col/3*3;
    for(int r = bigRow; r < bigRow + 3; r++) {
        for(int c = bigCol; c < bigCol + 3; c++ ) {
            if(board[r][c] == num) {
                return false;
            }
        }
    }

    return true;
}

#endif