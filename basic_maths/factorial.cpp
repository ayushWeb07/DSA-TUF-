#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach: TC - O(n) | SC - O(n)
class Solution {
public:
    int factorial(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }

        return n * factorial(n-1);
    }
};
