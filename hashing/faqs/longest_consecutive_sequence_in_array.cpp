#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n log n) | SC - O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());

        int size= nums.size();

        int cnt= 1;
        int max_cnt= INT_MIN;

        for(int i= 1; i < size; i++) {
            if(nums[i] == nums[i - 1]) {
                continue;
            }

            else {
                if(nums[i] == (nums[i - 1] + 1)) {
                    cnt++;
                } else {
                    max_cnt= max(max_cnt, cnt);
                    cnt= 1;
                }
            }
        }

        max_cnt= max(max_cnt, cnt);

        return max_cnt;
    }
};