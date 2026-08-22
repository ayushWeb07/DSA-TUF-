#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(R * log(C) * log(max_val - min_val)) | SC - O(1)
class Solution{
public:
    int findMinOfMatrix(vector<vector<int>>&matrix, int nRows, int nCols) {
        int minEle= INT_MAX;

        for (int i= 0; i< nRows; i++) {
            minEle= min(minEle, matrix[i][0]);
        }

        return minEle;
    }

    int findMaxOfMatrix(vector<vector<int>>&matrix, int nRows, int nCols) {
        int maxEle= INT_MIN;

        for (int i= 0; i< nRows; i++) {
            maxEle= max(maxEle, matrix[i][nCols - 1]);
        }

        return maxEle;
    }

    int findLesserEqualElements(vector<vector<int>>&matrix, int nRows, int nCols, int target) {

        int st, end, mid, ele, ans, tot= 0;

        for (int i= 0; i< nRows; i++) {
            st= 0;
            end= nCols - 1;
            ans= nCols;

            while (st <= end) {
                mid= (st + end) / 2;
                ele= matrix[i][mid];

                if (ele <= target) {
                    st= mid + 1;
                }

                else {
                    ans= mid;
                    end= mid - 1;
                }
            }

            tot+= ans;
        }

        return tot;
    }

    int findMedian(vector<vector<int>>&matrix) {
        int nRows= matrix.size();
        int nCols= matrix[0].size();

        int st= findMinOfMatrix(matrix, nRows, nCols);
        int end= findMaxOfMatrix(matrix, nRows, nCols);

        int mid;
        int req= (nRows * nCols) / 2;
        int ans= -1;

        while (st <= end) {
            mid= (st + end) / 2;

            if (findLesserEqualElements(matrix, nRows, nCols, mid) <= req) {
                st= mid + 1;
            }

            else {
                ans= mid;
                end= mid - 1;
            }
        }

        return ans;
    }
};