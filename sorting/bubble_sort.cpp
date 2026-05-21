#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int len= nums.size();

        for(int i=0; i<len-1; i++) {
            for(int j=0; j<len-1-i; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }

        return nums;
    }
};
