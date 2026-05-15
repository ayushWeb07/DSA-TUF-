#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach: TC - O(log10(n)) | SC - O(1)
class Solution {
public:
    int rev(int n, int r) {
        if(n <= 0) {
            return 0;
        }

        int d= n % 10;
        r= r * 10 + d;

        return rev(n / 10, r) * 10 + d;
    }

    int reverseNumber(int n) {
        return rev(n, 0);
    }
};