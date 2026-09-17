#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(log n)
class Solution {
public:
    double pow(double x, int n) {

        if (n == 0 || x == 1) {
            return 1;
        }

        else if (n == 1) {
            return x;
        }

        else {
            if (n % 2 == 0) {
                return pow(x * x, (n / 2));
            }

            else {
                return x * pow(x, n - 1);
            }
        }

    }

    double myPow(double x, int n) {
        long num= n;

        if (num < 0) {
            x= (1 / x);
            num*= -1;
        }

        return pow(x, num);
    }
};