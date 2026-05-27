#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int firstEle= nums.front();
        int len= nums.size();

        for(int i=1; i<len; i++) {
            swap(nums[i - 1], nums[i]);
        }

        nums[len - 1]= firstEle;
    }
};