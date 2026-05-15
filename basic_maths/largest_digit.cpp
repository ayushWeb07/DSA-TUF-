#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach: O(log10(n))
class Solution {
public:
    int largestDigit(int n) {
        int maxDigit= 0;

        while(n > 0) {
            int currDigit= n % 10;
            maxDigit= max(maxDigit, currDigit);
            n/= 10;
        }

        return maxDigit;
    }
};