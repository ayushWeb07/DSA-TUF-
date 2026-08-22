#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(R * log(C)) | SC - O(1)
class Solution {
public:
    int indexOfMaxElement(vector<vector<int>>& mat, int nRows, int colIdx) {
        int maxEle= -1;
        int resIdx= -1;

        for (int i= 0; i< nRows; i++) {
            if (mat[i][colIdx] >= maxEle) {
                maxEle= mat[i][colIdx];
                resIdx= i;
            }
        }

        return resIdx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int nRows= mat.size();
        int nCols= mat[0].size();

        int st= 0, end= nCols - 1;
        int mid, ele, maxRowIdx, left, right;

        while (st <= end) {
            mid= (st + end) / 2;
            maxRowIdx= indexOfMaxElement(mat, nRows, mid);

            ele= mat[maxRowIdx][mid];

            left= (mid - 1) >= 0? mat[maxRowIdx][mid - 1] : -1;
            right= (mid + 1) < nCols? mat[maxRowIdx][mid + 1] : -1;

            if ((ele > left) && (ele > right)) {
                return {maxRowIdx, mid};
            }

            else if (ele < left) {
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return {-1, -1};
    }
};