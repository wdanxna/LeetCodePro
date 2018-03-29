//
//  SurroundedRegions.cpp
//  leetcodepro
//
//  Created by drakeDan on 5/6/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "SurroundedRegions.h"
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void help(int i, int j, int w, int h, vector<vector<char>>& board, bool* have) {
    if (i < 0 || i >= h || j < 0 || j >= w) {
        return;
    }
    
    if (board[i][j] == 'x' || have[i*w + j]) {
        return;
    }
    
    have[i*w + j] = true;
    
    //up
    help(i - 1, j, w, h, board, have);
    //right
    help(i, j + 1, w, h, board, have);
    //down
    help(i + 1, j, w, h, board, have);
    //left
    help(i, j - 1, w, h, board, have);
}

void solve(vector<vector<char>>& board) {
    int h = (int)board.size();
    if (h == 0) return;
    int w = (int)board[0].size();
    bool have[h*w];
    
    for (int i = 0; i < h*w; i++) {
        have[i] = false;
    }
    
    //left
    for (int i = 0; i < h; i++) {
        if (board[i][0] == '0') {
            help(i, 0, w, h, board, have);
        }
    }
    
    // right
    for (int i = 0; i < h; i++) {
        if (board[i][w-1] == '0') {
            help(i, w-1, w, h, board, have);
        }
    }
    
    //top
    for (int i = 0; i < w; i++) {
        if (board[0][i] == '0') {
            help(0, i, w, h, board, have);
        }
    }
    
    //bottom
    for (int i = 0; i < w; i++) {
        if (board[h-1][i] == '0') {
            help(h-1, i, w, h, board, have);
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << have[i*w+j] << ",";
        }
        cout << endl;
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (have[i*w+j]) {
                board[i][j] = '0';
            } else {
                board[i][j] = 'x';
            }
        }
    }
}

void surroundedRegionsTest() {
//    vector<vector<char>> board = {{'x','x','x','x'},
//                                  {'x','0','0','x'},
//                                  {'x','x','0','x'},
//                                  {'x','0','x','x'}};
    
//    vector<vector<char>> board = {{'x','x','x'},
//                                  {'x','0','x'},
//                                  {'x','x','x'}};
    
//    vector<vector<char>> board = {{'x','0','x'}};
    vector<vector<char>> board = {{'0'}};
    
    solve(board);
//    cout << board.size() << endl;
//    cout << board[0].size() << endl;
    cout << board[0][0] << endl;
//    for (int i = 0; i < board.size(); i++) {
//        for (int j = 0; i < board[i].size(); j++) {
//            cout << board[i][j] << ",";
//        }
//        cout << endl;
//    }
}


