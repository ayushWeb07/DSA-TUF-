#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(N) | SC - O(N)
class Solution1 {
public:
    void rotateArray(vector<int>& nums, int k) {
        vector<int> temp;
        int len= nums.size();
        k= k % len;

        // put k -> n - 1
        for(int i=k; i<len; i++) {
            temp.push_back(nums[i]);
        }

        // put 0 -> k - 1
        for(int i=0; i<k; i++) {
            temp.push_back(nums[i]);
        }

        nums= temp;

    }
};

// TC - O(N) | SC - O(1)
class Solution2 {
public:
    void reverseArray(vector<int>& nums, int st, int end) {
        while (st < end) {
            swap(nums[st++], nums[end--]);
        }
    }

    void rotateArray(vector<int>& nums, int k) {
        int len= nums.size();
        k= k % len;

        // sort the left half: 0 -> k - 1
        reverseArray(nums, 0, k - 1);

        // sort the right half: k -> len - 1
        reverseArray(nums, k, len - 1);

        // sort the entire array
        reverseArray(nums, 0, len - 1);
    }
};