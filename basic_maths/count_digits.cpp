#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1: TC - O(log10(n)) | SC - O(log10(n))
class Solution1 {
public:
    int countDigit(int n) {
        return to_string(n).size();
    }
};

// approach 2: O(log10(n)) | SC - O(log10(n))
class Solution2 {
public:
    int count(int n) {
        if(n <= 0) {
            return 0;
        }

        return 1 + count(n / 10);
    }

    int countDigit(int n) {
        if(n < 10) {
            return 1;
        }

        return count(n);
    }
};