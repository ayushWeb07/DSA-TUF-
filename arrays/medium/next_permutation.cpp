#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(1)
class Solution {
public:
    void reverse(vector<int>& nums, int st, int end) {
        while(st < end) {
            swap(nums[st++], nums[end--]);
        }
    }

    void nextPermutation(vector<int>& nums) {
        int size= nums.size();

        int ind= -1;

        for(int i= (size - 2); i>= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind= i;
                break;
            }
        }

        if(ind == -1) {
            reverse(nums, 0, size - 1);
            return;
        }

        for(int i= (size - 1); i>= ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums, ind + 1, size - 1);
    }
};