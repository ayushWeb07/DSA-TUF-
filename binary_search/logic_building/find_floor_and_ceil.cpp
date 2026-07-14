#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution {
public:
    int getFloorOfTarget(vector<int>& nums, int size, int x) {
        int st= 0, end= size - 1;
        int ans= -1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            if (nums[mid] <= x) {
                ans= nums[mid];
                st= mid + 1;
            }

            else {
                end= mid - 1;
            }
        }

        return ans;
    }

    int getCeilOfTarget(vector<int>& nums, int size, int x) {
        int st= 0, end= size - 1;
        int ans= -1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            if (nums[mid] >= x) {
                ans= nums[mid];
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int size= nums.size();

        int f= getFloorOfTarget(nums, size, x);
        int c= getCeilOfTarget(nums, size, x);

        return {f, c};
    }
};
