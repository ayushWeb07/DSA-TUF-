#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(2 ^ n) | SC - O(n)
class Solution{
public:
    void countSubsequences(vector<int>& nums, int n, int k, int idx, int s, int& c) {
        if (s == k) {
            c++;
            return;
        }

        if ((s > k) || (idx == n)) {
            return;
        }

        // take the current index element
        checkIfExists(nums, n, k, idx + 1, s + nums[idx], c);

        // do not take the current index element
        checkIfExists(nums, n, k, idx + 1, s, c);
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        int n= nums.size();
        int cnt= 0;

        countSubsequences(nums, n, k, 0, 0, cnt);

        return cnt;
    }
};