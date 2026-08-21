#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(n * log(S)) | SC - O(1)
class Solution {
public:
    bool checkIfSufficientSplits(vector<int> &nums, int k, int maxSum) {
        int sum= 0, reqSplits= 0;

        for (int n: nums) {
            if ((sum + n) <= maxSum) {
                sum+= n;
            }

            else {
                reqSplits++;
                sum= n;
            }
        }

        if (sum != 0) reqSplits++;

        return reqSplits <= k;
    }

    int largestSubarraySumMinimized(vector<int> &a, int k) {
        int size= a.size();

        // find the start and end points
        int st= *max_element(a.begin(), a.end());
        int end= accumulate(a.begin(), a.end(), 0);
        int mid;
        int ans= -1;

        // handle edge case
        if (size == k) return st;

        while (st <= end) {
            mid= (st + end) / 2;

            if (checkIfSufficientSplits(a, k, mid)) {
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