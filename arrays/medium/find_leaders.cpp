#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(n)
class Solution1 {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> temp;
        int len= nums.size();

        for(int i=len-1; i>=0; i--) {
            if(temp.size() == 0 || nums[i] > temp.front()) {
                temp.insert(temp.begin(), nums[i]);
            }
        }

        return temp;
    }
};

// TC - O(n) | SC - O(n)
class Solution2 {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> temp;
        int len= nums.size();

        for(int i=len-1; i>=0; i--) {
            if(temp.size() == 0 || nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
};