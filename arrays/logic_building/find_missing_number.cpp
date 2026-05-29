#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n log n) | SC - O(1)
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());

        // check if [0 : n-1] exist in the array
        for(int i= 0; i<n; i++){
            if(nums[i] != i) {
                return i;
            }
        }

        // check n exist in the array
        if(nums[n - 1] != n) {
            return n;
        }
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();

        // if 0 -> n is present, then sum of first n nums == sum of arr
        int expectedSum= (n * (n + 1)) / 2;

        // calc sum of the array elements
        int actualSum= 0;
        for (int ele: nums) {
            actualSum+= ele;
        }

        // missing num -> expected sum - actual sum
        return (expectedSum - actualSum);
    }
};