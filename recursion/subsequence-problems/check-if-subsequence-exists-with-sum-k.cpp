#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(2 ^ n) | SC - O(n)
class Solution{
public:
    bool checkIfExists(vector<int>& nums, int n, int k, int idx, int s) {
        if (s == k) {
            return true;
        }

        if ((s > k) || (idx == n)) {
            return false;
        }

        // take the current index element
        bool c1= checkIfExists(nums, n, k, idx + 1, s + nums[idx]);

        // do not take the current index element
        bool c2= checkIfExists(nums, n, k, idx + 1, s);

        return (c1 || c2);
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int n= nums.size();

        return checkIfExists(nums, n, k, 0, 0);
    }
};