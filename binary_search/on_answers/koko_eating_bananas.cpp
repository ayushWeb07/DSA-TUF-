#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(n * log(m)) | SC - O(1)
class Solution {
public:
    bool checkDivisionResultSatisfiesThreshold(vector<int> &nums, int size, int divisor, int limit) {
        int s= 0;

        for(int i= 0; i< size; i++) {
            s+= (nums[i] + divisor - 1) / divisor;

            if (s > limit) {
                return false;
            }
        }

        return true;
    }

    int minimumRateToEatBananas(vector<int> nums, int h) {
        int size= nums.size();
        bool c;

        int maxHours = *max_element(nums.begin(), nums.end());

        int st= 1, end= maxHours;
        int ans= -1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            c= checkDivisionResultSatisfiesThreshold(nums, size, mid, h);

            if(c) {
                ans= mid;
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return ans;
    }
};
