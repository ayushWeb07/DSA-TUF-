#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int>& nums) {
    int len= nums.size();
    int j;

    for (int i=1; i<len; i++) {
        j= i;

        while ((j > 0) && (nums[j-1] > nums[j])) {
            swap(nums[j], nums[j-1]);
            j--;
        }
    }

    return nums;
}