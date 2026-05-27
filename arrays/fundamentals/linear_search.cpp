#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        int len= nums.size();

        for(int i=0; i<len; i++) {
            if(nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};