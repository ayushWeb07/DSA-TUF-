#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n * 2^n) | SC - O(n)
class Solution {
public:
    void buildAns(vector<int>& nums, int n, int idx, vector<int>& lst, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(lst);
            return;
        }

        // take the current one
        lst.push_back(nums[idx]);
        buildAns(nums, n, idx + 1, lst, ans);
        lst.pop_back();

        // do not take current one -> skip all the elements which are duplicates of current one
        for (int i= idx + 1; i < n; i++) {
            if (nums[i] != nums[idx]) {
                buildAns(nums, n, i, lst, ans);
                return;
            }
        }

        // no other element found than the current one, hence reached end of the array
        buildAns(nums, n, n, lst, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the input array
        sort(nums.begin(), nums.end());

        int n= nums.size();
        vector<int> lst;
        vector<vector<int>> ans;

        buildAns(nums, n, 0, lst, ans);

        return ans;
    }
};