#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size= nums.size();
        int sum= 0, maxSum= INT_MIN;

        for(int n: nums) {
            sum+= n;
            maxSum= max(maxSum, sum);

            if (sum < 0) {
                sum= 0;
            }
        }

        return maxSum;
    }
};