#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(n * log(sum(nums))) | SC - O(1)
class Solution {
public:
    bool checkIfSufficientMaxPages(vector<int> &nums, int n, int m, int maxPages) {
        int sumPages= 0, reqStuds= 1;

        for (int pages: nums) {
            if ((sumPages + pages) <= maxPages) {
                sumPages+= pages;
            }

            else {
                reqStuds++;
                sumPages= pages;
            }
        }

        return reqStuds <= m;
    }


    int findPages(vector<int> &nums, int m)  {
        int n= nums.size();

        // edge case: more students than books
        if (m > n) {
            return -1;
        }

        // find the start and end points
        int st= *max_element(nums.begin(), nums.end());
        int end= accumulate(nums.begin(), nums.end(), 0);
        int mid;
        int ans= -1;

        while (st <= end) {
            mid= (st + end) / 2;

            if (checkIfSufficientMaxPages(nums, n, m, mid)) {
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