//
//  sudokuSolver.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/1/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "sudokuSolver.h"

static unordered_set<char> preset = {'1','2','3','4','5','6','7','8','9'};

void solver(vector<vector<char>> board, int row, int col, vector<vector<char>> &ret) {
    if (board[row][col] != '.') {
        if (row == 8 && col == 8) {
            ret = board;
            return;
        }
        else if (++col >= 9) {
            ++row;
            col = 0;
        }
        solver(board, row, col, ret);
        return;
    }
    
    // calculate solve space
    unordered_set<char> set = preset;
    // filter colum
    for (int k = 0; k < 9; k++) {
        char searched = board[k][col];
        if (searched != '.' && set.find(searched) != set.end()) {
            set.erase(searched);
        }
    }
    // filter row
    for (int k = 0; k < 9; k++) {
        char searched = board[row][k];
        if (searched != '.' && set.find(searched) != set.end()) {
            set.erase(searched);
        }
    }
    // filter 3*3
    int square_row_offset = row / 3;
    int square_col_offset = col / 3;
    for (int k = square_row_offset * 3; k < square_row_offset * 3 + 3; k++) {
        for (int l = square_col_offset * 3; l < square_col_offset * 3 + 3; l++) {
            char searched = board[k][l];
            if (searched != '.' && set.find(searched) != set.end()) {
                set.erase(searched);
            }
        }
    }
    
    for (char ele: set) {
        board[row][col] = ele;
        
        if (row == 8 && col == 8) {
            ret = board;
            return;
        }
        
        solver(board, row, col+1, ret);
    }
}


vector<vector<char>> sudokuSolver(vector<vector<char>> &board) {
    vector<vector<char>> ret;
    solver(board, 0, 0, ret);
    return ret;
}

void printSudokuBoard(vector<vector<char>> &board) {
    if (board.size() == 0) {
        cout << "empty board" <<endl;
        return;
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (i == 3 || i == 7 || i == 11) {
                cout << "-";
            }
            else if (j == 3 || j == 7 || j == 11){
                cout << "|";
            }
            else {
                int vi = i ,vj = j;
                if (i > 3 && i < 7) vi = i-1;
                else if (i > 7) vi = i - 2;
                if (j > 3 && j < 7) vj = j-1;
                else if (j > 7) vj = j - 2;
                cout << board[vi][vj];
            }
        }
        cout << endl;
    }
}

void sudokuSolverTest() {
    vector<vector<char>> board = {  {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
    
    vector<vector<char>> hardBoard = {  {'.','.','.','.','.','1','9','.','8'},
                                        {'.','9','.','.','.','.','.','.','.'},
                                        {'3','4','5','.','.','2','1','.','.'},
                                        {'.','.','.','3','.','9','.','6','.'},
                                        {'.','.','6','7','2','.','.','.','.'},
                                        {'5','.','7','.','.','.','.','.','3'},
                                        {'2','5','.','.','4','.','.','.','.'},
                                        {'.','.','.','.','1','6','.','.','.'},
                                        {'.','8','1','.','.','7','4','.','.'}};
    printSudokuBoard(board);
    vector<vector<char>> newBoard = sudokuSolver(board);
    cout << endl << "----Solved----" << endl << endl;
    printSudokuBoard(newBoard);
}
