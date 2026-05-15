#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach: O(log10(n))
class Solution {
public:
    int reverseNumber(int n) {
        if(n < 10) {
            return n;
        }

        int rev= 0;

        while (n > 0) {
            int d= n % 10;
            rev= rev * 10 + d;
            n/= 10;
        }

        return rev;
    }

    bool isPalindrome(int n) {
        return n == reverseNumber(n);
    }
};