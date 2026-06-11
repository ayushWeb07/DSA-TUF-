#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(n^2)
class Solution1 {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> res (n, vector<int>(n, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                res[j][n - i - 1]= matrix[i][j];
            }
        }

        matrix= res;
    }
};

// TC - O(n^2) | SC - O(1)
class Solution2 {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();

        // transpose the matrix
        for(int i=0; i<=(n - 2); i++) {
            for(int j= (i + 1); j<=(n - 1); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the row elements in the matrix
        int st, end;

        for(int i=0; i<n; i++) {
            st= 0;
            end= n - 1;

            while(st < end) {
                swap(matrix[i][st], matrix[i][end]);
                st++;
                end--;
            }
        }
    }
};

// TC - O(n^2) | SC - O(1)
class Solution3 {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();

        // transpose the matrix
        for(int i=0; i<=(n - 2); i++) {
            for(int j= (i + 1); j<=(n - 1); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the row elements in the matrix
        int st, end;

        for(int i=0; i<n; i++) {
            st= 0;
            end= n - 1;

            while(st < end) {
                swap(matrix[i][st++], matrix[i][end--]);
            }
        }
    }
};