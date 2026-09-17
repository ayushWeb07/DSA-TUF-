#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(9^m) | SC - O(m)
class Solution {
public:

    bool isPlacementValid(vector<vector<char>>& board, int n, int i, int j, int digit) {
        // check row
        for (int col= 0; col< n; col++) {
            if (board[i][col] == (char)digit) {
                return false;
            }
        }

        // check col
        for (int row= 0; row< n; row++) {
            if (board[row][j] == (char)digit) {
                return false;
            }
        }

        // sub grid check
        int startRow= (i / 3) * 3;
        int startCol= (j / 3) * 3;

        int effRow, effCol;

        for (int tI= 0; tI< 3; tI++) {
            for (int tJ= 0; tJ< 3; tJ++) {
                effRow= startRow + tI;
                effCol= startCol + tJ;

                if (board[effRow][effCol] == (char)digit) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int n) {

        for (int i= 0; i< n; i++) {
            for (int j= 0; j< n; j++) {
                // missing cell found
                if (board[i][j] == '.') {
                    for (int digit= 1; digit <= 9; digit++) {

                        if (isPlacementValid(board, n, i, j, digit)) {

                            board[i][j]= (char)digit;

                            // traverse the next path
                            bool val= solve(board, n);

                            if (val) {
                                return true;
                            }

                            board[i][j]= '.';
                        }
                    }

                    // no digit can fill the missing place
                    return false;
                }
            }
        }

        // no more missing cells to fill
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        int n= 9;

        solve(board, n);
    }
};