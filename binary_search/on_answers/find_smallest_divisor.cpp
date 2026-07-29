#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force -> TC - O(m * n) | SC - O(1)
class Solution1 {
public:
    int smallestDivisor(vector<int> &nums, int limit) {
        int size= nums.size();
        int s;

        int maxi = *max_element(nums.begin(), nums.end());

        for(int i=1; i<= maxi; i++) {
            s= 0;

            for(int j= 0; j< size; j++) {
                s+= (nums[j] + i - 1) / i;

                if (s > limit) {
                    break;
                }
            }

            if (s <= limit) {
                return i;
            }
        }

        return maxi;
    }
};

// optimal -> TC - O(n * log(m)) | SC - O(1)
class Solution2 {
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

    int smallestDivisor(vector<int> &nums, int limit) {
        int size= nums.size();
        bool c;

        int maxi = *max_element(nums.begin(), nums.end());

        int st= 1, end= maxi;
        int ans= -1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            c= checkDivisionResultSatisfiesThreshold(nums, size, mid, limit);

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