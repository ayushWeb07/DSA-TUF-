#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution{
public:
    int findStartingIndex(vector<int> &nums, int size, int target) {
        int st= 0, end= size - 1;
        int ans= -1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            if(nums[mid] == target) {
                ans= mid;
                end= mid - 1;
            }

            else if(nums[mid] > target) {
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return ans;
    }

    int findEndingIndex(vector<int> &nums, int size, int target) {
        int st= 0, end= size - 1;
        int ans= -1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            if(nums[mid] == target) {
                ans= mid;
                st= mid + 1;
            }

            else if(nums[mid] > target) {
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int size= nums.size();

        int s= findStartingIndex(nums, size, target);
        int e= findEndingIndex(nums, size, target);

        return {s, e};
    }
};