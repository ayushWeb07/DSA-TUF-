#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        int left= st; // start of left half
        int right= mid + 1; // start of right half
        vector<int> temp;

        while ((left <= mid) && (right <= end)) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }

            else {
                temp.push_back(nums[right++]);
            }
        }

        // left half has exhausted but there are still elements in right half
        while (right <= end) {
            temp.push_back(nums[right++]);
        }

        // right half has exhausted but there are still elements in left half
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        // put all elements from the temp back to org array
        for (int i= st; i<=end; i++) {
            nums[i]= temp[i - st];
        }
    }

    void mS(vector<int>& nums, int st, int end) {
        if (st >= end) {
            return;
        }

        // find the mid index
        int mid= (st + end) / 2;

        // divide the left half: st -> mid
        mS(nums, st, mid);

        // divide the right half: mid + 1 -> end
        mS(nums, mid + 1, end);

        // merge both the halfs
        merge(nums, st, mid, end);
    }

    vector<int> mergeSort(vector<int>& nums) {
        int st= 0;
        int end= nums.size() - 1;

        mS(nums, st, end);

        return nums;
    }
};