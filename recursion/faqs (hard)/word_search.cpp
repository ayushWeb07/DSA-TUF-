#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(N * 3^L) | SC - O(L)
class Solution {
public:
    bool checkIfExists(vector<vector<char>>& board, int nRows, int nCols, string& w, int n, int idx, int rowIdx, int colIdx) {
        if (idx == n) {
            return true;
        }

        if ((board[rowIdx][colIdx] == ' ') || (board[rowIdx][colIdx] != w[idx])) {
            return false;
        }

        char ch= board[rowIdx][colIdx];

        board[rowIdx][colIdx]= ' ';

        bool ans= false;

        // top
        if ((rowIdx - 1) >= 0) {
            ans|= checkIfExists(board, nRows, nCols, w, n, idx + 1, rowIdx - 1, colIdx);
        }

        // right
        if ((colIdx + 1) < nCols) {
            ans|= checkIfExists(board, nRows, nCols, w, n, idx + 1, rowIdx, colIdx + 1);
        }

        // bottom
        if ((rowIdx + 1) < nRows) {
            ans|= checkIfExists(board, nRows, nCols, w, n, idx + 1, rowIdx + 1, colIdx);
        }

        // left
        if ((colIdx - 1) >= 0) {
            ans|= checkIfExists(board, nRows, nCols, w, n, idx + 1, rowIdx, colIdx - 1);
        }

        board[rowIdx][colIdx]= ch;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int nRows= board.size();
        int nCols= board[0].size();
        int n= word.size();

        // edge case -> single cell
        if ((nRows == 1) && (nCols == 1)) {
            return (board[0][0] == word[0]);
        }

        for (int i= 0; i< nRows; i++) {
            for (int j= 0; j< nCols; j++) {
                if (board[i][j] == word[0]) {
                    // its a valid starting point
                    // check if the word can be formed in any way by starting from here
                    if (checkIfExists(board, nRows, nCols, word, n, 0, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};