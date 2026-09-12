#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(2 ^ n) | SC - O(n)
class Solution {
public:
    void buildAns(vector<int>& nums, int n, int k, vector<int>& lst, vector<vector<int>>& ans, int idx, int s) {

        if (s == k) {
            ans.push_back(lst);
            return;
        }

        if ((s > k) || (idx == n)) {
            return;
        }

        // take the current
        lst.push_back(nums[idx]);
        buildAns(nums, n, k, lst, ans, idx, s + nums[idx]);
        lst.pop_back();

        // don't take the current
        buildAns(nums, n, k, lst, ans, idx + 1, s);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> lst;
        int n= candidates.size();

        buildAns(candidates, n, target, lst, ans, 0, 0);

        return ans;
    }
};