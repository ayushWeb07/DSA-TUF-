#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(2 ^ n) | SC - O(n)
class Solution {
public:
    void buildAns(vector<int>& nums, int n, int idx, int s, vector<int>& ans) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }

        // take the current index
        buildAns(nums, n, idx + 1, s + nums[idx], ans);

        // do not take the current index
        buildAns(nums, n, idx + 1, s, ans);
    }


    vector<int> subsetSums(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;

        buildAns(nums, n, 0, 0, ans);

        return ans;
    }
};