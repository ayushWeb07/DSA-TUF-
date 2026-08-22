#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(log(m*n)) | SC - O(1)
class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int nRows= mat.size();
        int nCols= mat[0].size();

        int st= 0, end= (nRows * nCols) - 1;
        int mid, ele;

        while (st <= end) {
            mid= (st + end) / 2;
            ele= mat[mid / nCols][mid % nCols];

            if (ele == target) {
                return true;
            }

            else if (ele > target) {
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return false;
    }
};