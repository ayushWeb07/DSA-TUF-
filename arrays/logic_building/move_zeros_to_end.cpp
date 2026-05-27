#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(n)
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int len= nums.size();
        vector<int> temp;

        for(int ele: nums) {
            if(ele != 0) {
                temp.push_back(ele);
            }
        }

        int i= 0;

        for(int ele: temp) {
            nums[i++]= ele;
        }

        while(i < len) {
            nums[i++]= 0;
        }
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int j= -1;
        int len= nums.size();

        // find the first zero index
        for (int i=0; i<len; i++) {
            if(nums[i] == 0) {
                j= i;
                break;
            }
        }

        // no zero elements found
        if (j == -1) {
            return;
        }

        for(int i=j+1; i<len; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};