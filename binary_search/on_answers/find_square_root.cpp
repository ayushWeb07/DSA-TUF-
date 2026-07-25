#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution {
public:
    int floorSqrt(int n)  {
        int st= 1, end= n / 2;
        long long mid;
        int ans= -1;

        // handle the edge cases
        if(n == 0) return 0;

        if(n == 1) return 1;


        while (st <= end) {
            mid= (long long)(st + end) / 2;

            if((long long)(mid * mid) > (long long)(n)) {
                end= mid - 1;
            }

            else if((long long)(mid * mid) < (long long)(n)) {
                ans= mid;
                st= mid + 1;
            }

            else {
                return (int)(mid);
            }
        }

        return ans;
    }
};