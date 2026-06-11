#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(r^2) | SC - O(r)
class Solution {
public:
    int ncr(int n, int r) {
        int res= 1;

        for(int i=0; i<r; i++) {
            res*= (n - i);
            res/= (i + 1);
        }

        return res;
    }

    int pascalTriangleI(int r, int c) {
        return ncr(r - 1, c - 1);
    }

    vector<int> pascalTriangleII(int r) {
        vector<int> res;

        for(int c=1; c<=r; c++) {
            res.push_back(pascalTriangleI(r, c));
        }

        return res;
    }
};