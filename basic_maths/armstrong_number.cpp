#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach: TC - O(log10(n)) | SC - O(log10(n))
class Solution {
public:
    bool isArmstrong(int n) {
        int size= to_string(n).size();

        int t= n, s= 0;

        while(t > 0) {
            int d= t % 10;
            s+= pow(d, size);
            t/= 10;
        }

        return s == n;
    }
};