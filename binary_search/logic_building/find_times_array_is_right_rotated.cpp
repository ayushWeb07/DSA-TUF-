#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int size= nums.size();
        int st= 0, end= size - 1;
        int mid;
        int mini= INT_MAX;
        int mini_idx= -1;

        while (st <= end) {
            mid= (st + end) / 2;

            if(nums[mid] < mini) {
                mini= nums[mid];
                mini_idx= mid;
            }

            // check if left half is sorted
            if(nums[st] <= nums[mid]) {
                if(nums[st] < mini) {
                    mini= nums[st];
                    mini_idx= st;
                }

                st= mid + 1;
            }

            // right half is sorted
            else {
                if(nums[mid] < mini) {
                    mini= nums[mid];
                    mini_idx= mid;
                }

                end= mid - 1;
            }

        }

        return mini_idx;
    }
};