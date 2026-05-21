#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElementIndex(vector<int>& nums, int st) {
        int len= nums.size();
        int minEle= INT_MAX;
        int minIdx= -1;

        for (int i=st; i<len; i++) {
            if (nums[i] < minEle) {
                minEle= nums[i];
                minIdx= i;
            }
        }

        return minIdx;
    }

    vector<int> selectionSort(vector<int>& nums) {
        int len= nums.size();
        int minIdx;

        for (int i=0; i<len-1; i++) {
            // find the min element index in range: i -> len-1
            minIdx= minElementIndex(nums, i);

            // swap with current element
            if (i != minIdx) {
                swap(nums[i], nums[minIdx]);
            }
        }

        return nums;
    }
};