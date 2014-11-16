//
//  isValidSudoku.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/29/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "isValidSudoku.h"


bool isValidSudoku(vector<vector<char>> &board) {
    unordered_set<int> column;
    unordered_set<int> square;
    unordered_set<int> row;
 
    
    // check for colum
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char item = board[j][i];
            if (item != '.') {
                int num = atoi(&item);
                if (column.find(num) == column.end()){
                    column.insert(atoi(&item));
                }
                else {
                    return false;
                }
            }
        }
        column.clear();
    }

    // check for row
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char item = board[i][j];
            if (item != '.') {
                int num = atoi(&item);
                if (row.find(num) == row.end()) {
                    row.insert(num);
                }
                else {
                    return false;
                }
            }
        }
        row.clear();
    }
    
    // check for 3x3
    for (int offsetY = 0; offsetY < 3; offsetY++) {
        for (int offsetX = 0; offsetX < 3; offsetX++) {
            
            for (int i = 3*offsetY; i < 3*offsetY+3; i++) {
                for (int j = 3*offsetX; j < 3*offsetX+3; j++) {
                    char item = board[i][j];
                    if (item != '.') {
                        int num = atoi(&item);
                        if (square.find(num) == square.end()) {
                            square.insert(num);
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
            square.clear();
            
        }
    }
    
    return true;
}

void isValidSudokuTest() {
    vector<vector<char>> board = {  {'.','8','7','6','5','4','3','2','1'},
                                    {'2','.','.','.','.','.','.','.','.'},
                                    {'3','.','.','.','.','.','.','.','.'},
                                    {'4','.','.','.','.','.','.','.','.'},
                                    {'5','.','.','.','.','.','.','.','.'},
                                    {'6','.','.','.','.','.','.','.','.'},
                                    {'7','.','.','.','.','.','.','.','.'},
                                    {'8','.','.','.','.','.','.','.','.'},
                                    {'9','.','.','.','.','.','.','.','.'}};
    cout << isValidSudoku(board) << endl;
}