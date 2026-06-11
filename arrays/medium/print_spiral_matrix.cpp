#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(m * n) | SC - O(m * n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nRows= matrix.size();
        int nCols= matrix[0].size();

        vector<int> ans;

        // initialize the position pointers
        int left= 0, right= nCols - 1;
        int top= 0, bottom= nRows - 1;

        while((top <= bottom) && (left <= right)) {
            // left -> right
            for(int i=left; i<=right; i++) {
                ans.push_back(matrix[top][i]);
            }

            top++;

            // top -> bottom
            for(int i=top; i<=bottom; i++) {
                ans.push_back(matrix[i][right]);
            }

            right--;

            // right -> left
            if (top <= bottom) {
                for(int i=right; i>=left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            // bottom -> top
            if(left <= right) {
                for(int i=bottom; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return ans;
    }
};