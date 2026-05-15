#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1: TC - O(n) | SC - O(1)
class Solution1 {
public:
    bool isPerfect(int n) {
        int s= 0;

        for(int i=1; i<=(n/2); i++) {
            if(n % i == 0) {
                s+= i;
            }
        }

        return n == s;
    }
};

// approach 2: TC - O(sqrt(n)) | SC - O(1)
class Solution2 {
public:
    bool isPerfect(int n) {

        if(n <= 1) {
            return false;
        }

        int s= 1;

        for(int i=2; (i*i)<=n; i++) {

            if(n % i == 0) {
                s+= i;

                if(i != (n/i)) {
                    s+= (n/i);
                }
            }

        }

        return s == n;
    }
};