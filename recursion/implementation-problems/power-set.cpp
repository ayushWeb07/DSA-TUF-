#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n * 2^n) | SC - O(n)
class Solution {
public:
    void buildPowerSet(vector<int>& nums, int n, int idx, vector<int>& lst, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(lst);
            return;
        }

        // take the currect index
        lst.push_back(nums[idx]);
        buildPowerSet(nums, n, idx + 1, lst, ans);
        lst.pop_back();

        // don't take the current index
        buildPowerSet(nums, n, idx + 1, lst, ans);
    }

    vector<vector<int>> powerSet(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> lst;

        // bulild the power set using the recurrsive function
        buildPowerSet(nums, n, 0, lst, ans);

        return ans;
    }
};