#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution{
public:
    int search(vector<int> &nums, int target){
        int size= nums.size();
        int st= 0, end= size - 1;
        int mid;

        while(st <= end) {
            mid= (st + end) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] > target) {
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return -1;
    }
};
