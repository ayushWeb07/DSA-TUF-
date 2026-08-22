#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(R * log(C)) | SC - O(1)
class Solution {
public:
    int rowWithMax1s(vector < vector < int >> & mat) {
        int nRows= mat.size();
        int nCols= mat[0].size();

        int maxOnes= 0, resIdx= -1;
        int st, end, mid, firstdx, totalOnes;

        for (int i= 0; i< nRows; i++) {

            // do binary search to calculate total ones in individual rows
            st= 0;
            end= nCols - 1;
            mid= -1;
            firstdx= nCols;

            while (st <= end) {
                mid= (st + end) / 2;

                if (mat[i][mid] == 1) {
                    firstdx= mid;
                    end= mid - 1;
                }

                else {
                    st= mid + 1;
                }
            }

            totalOnes= nCols - firstdx;

            if (totalOnes > maxOnes) {
                maxOnes= totalOnes;
                resIdx= i;
            }
        }

        return resIdx;
    }
};