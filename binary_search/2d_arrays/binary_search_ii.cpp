#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(m + n) | SC - O(1)
class Solution{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int nRows= matrix.size();
        int nCols= matrix[0].size();

        int r= nRows - 1;
        int c= 0;
        int ele;

        while ((r >= 0) && (c < nCols)) {
            ele= matrix[r][c];

            if (ele == target) {
                return true;
            }

            else if (ele > target) {
                r--;
            }

            else {
                c++;
            }
        }

        return false;
    }
};