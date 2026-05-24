#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getPartitionIndex(vector<int>& nums, int st, int end) {
        int i= st, j= end;

        int pivotEle= nums[st];

        while (i < j) {

            // find first element from left which is > pivotEle
            while (nums[i] <= pivotEle && i <= end) {
                i++;
            }

            // find first element from right which is <= pivotEle
            while (nums[j] > pivotEle && j >= st) {
                j--;
            }

            // i -> first element from left which is > pivotEle | j -> first element from right which is <= pivotEle
            if(i < j) {
                swap(nums[i], nums[j]);
            }

        }

        swap(nums[j], nums[st]);

        return j;
    }

    void qS(vector<int>& nums, int st, int end) {
        if (st < end) {
            // find partition index
            int pIdx= getPartitionIndex(nums, st, end);

            // quick sort left half: st -> pIdx - 1
            qS(nums, st, pIdx - 1);

            // quick sort right half: pIdx + 1 -> end
            qS(nums, pIdx + 1, end);
        }
    }

    vector<int> quickSort(vector<int>& nums) {
        int st= 0, end= nums.size() - 1;
        qS(nums, st, end);
        return nums;
    }
};
