#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(r) | SC - O(1)
class Solution1 {
public:
    int ncr(int n, int r) {
        int res= 1;

        for(int i=1; i<=r; i++) {
            res*= (n - i + 1);
            res/= i;
        }

        return res;
    }

    int pascalTriangleI(int r, int c) {
        return ncr(r - 1, c - 1);
    }
};

// TC - O(r) | SC - O(1)
class Solution2 {
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
};