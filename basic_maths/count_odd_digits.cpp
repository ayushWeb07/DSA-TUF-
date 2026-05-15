#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1: TC - O(log10(n)) | SC - O(log10(n))
class Solution1 {
public:
    int countOddDigit(int n) {
        int c= 0;

        while(n > 0) {
            int d= n % 10;

            if(d % 2 != 0) {
                c++;
            }

            n/= 10;
        }

        return c;
    }
};

// approach 2: TC - O(log10(n)) | SC - O(log10(n))
class Solution2 {
public:
    int count(int n) {
        if(n <= 0) {
            return 0;
        }

        // last digit is even
        if((n % 10) % 2 == 0) {
            return count(n / 10);
        }

        // last digit is odd
        else {
            return 1 + count(n / 10);
        }
    }

    int countOddDigit(int n) {
        return count(n);
    }
};