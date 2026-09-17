#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(N!) | SC - O(N^2)
class Solution {
public:
    bool isQueenPlacementValid(vector<string>& board, int n, int row, int col) {
        // top check
        int tR= row;

        while (tR >= 0) {
            if (board[tR][col] == 'Q') {
                return false;
            }

            tR--;
        }

        // left diagonal check
        tR= row;
        int tC= col;

        while ((tR >= 0) && (tC >= 0)) {
            if (board[tR][tC] == 'Q') {
                return false;
            }

            tR--;
            tC--;
        }

        // right diagonal check
        tR= row;
        tC= col;

        while ((tR >= 0) && (tC < n)) {
            if (board[tR][tC] == 'Q') {
                return false;
            }

            tR--;
            tC++;
        }

        return true;
    }

    void buildAns(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // explore by putting at all the column indexes
        for (int col= 0; col< n; col++) {
            if (isQueenPlacementValid(board, n, row, col)) {
                board[row][col]= 'Q';

                // explore the board further from this point
                buildAns(row + 1, n, board, ans);

                board[row][col]= '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string st= "";

        // create the row string
        for (int i= 0; i< n; i++) {
            st+= ".";
        }

        // create the board
        for (int i= 0; i< n; i++) {
            board.push_back(st);
        }

        // build the ans
        buildAns(0, n, board, ans);

        return ans;
    }
};