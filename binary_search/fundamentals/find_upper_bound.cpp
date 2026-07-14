#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int size= nums.size();
        int st= 0, end= size - 1;
        int ans= size;
        int mid;

        while(st <= end) {
            mid= (st + end) / 2;

            if(nums[mid] == x) {
                st= mid + 1;
            }

            else if(nums[mid] > x) {
                ans= mid;
                end= mid - 1;
            }

            else {
                st= mid + 1;
            }
        }

        return ans;
    }
};