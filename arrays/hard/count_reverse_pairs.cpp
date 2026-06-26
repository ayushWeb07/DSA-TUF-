#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n log n) | SC - O(n)
class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        int left= st; // start of left half
        int right= mid + 1; // start of right half
        vector<int> temp;

        while ((left <= mid) && (right <= end)) {
            if(nums[left] > nums[right]) {
                temp.push_back(nums[right++]);
            }

            else {
                temp.push_back(nums[left++]);
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

    void countPairs(vector<int>& nums, int st, int mid, int end, int& cnt) {
        int left= st; // start of left half
        int right= mid + 1; // start of right half

        while ((left <= mid) && (right <= end)) {
            if((long long)(nums[left]) > (2LL * nums[right])) {
                right++;
            }

            else {
                left++;
                cnt+= (right - (mid + 1));
            }
        }

        while (left <= mid) {
            left++;
            cnt+= (right - (mid + 1));
        }
    }

    void mS(vector<int>& nums, int st, int end, int& cnt) {
        if (st >= end) {
            return;
        }

        // find the mid index
        int mid= (st + end) / 2;

        // sort the left half: st -> mid
        mS(nums, st, mid, cnt);

        // sort the right half: mid + 1 -> end
        mS(nums, mid + 1, end, cnt);

        // count the no. of pairs
        countPairs(nums, st, mid, end, cnt);

        // merge both the halfs
        merge(nums, st, mid, end);
    }

    void mergeSort(vector<int>& nums, int& cnt) {
        int st= 0;
        int end= nums.size() - 1;

        mS(nums, st, end, cnt);
    }


    int reversePairs(vector<int>& nums) {
        int cnt= 0;
        mergeSort(nums, cnt);
        return cnt;
    }
};