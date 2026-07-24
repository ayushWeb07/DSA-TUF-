#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(1)
class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
        int size= nums.size();
        int st= 0, end= size - 1;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            if(nums[mid] == k) {
                return true;
            }

            else if((nums[st] == nums[mid]) && (nums[mid] == nums[end])) {
                st++;
                end--;
                continue;
            }

            else {
                // check if left half is sorted
                if(nums[st] <= nums[mid]) {

                    if((nums[st] <= k) && (k <= nums[mid])) {
                        end= mid - 1;
                    }

                    else {
                        st= mid + 1;
                    }

                }

                // right half is sorted
                else {

                    if((nums[mid] <= k) && (k <= nums[end])) {
                        st= mid + 1;
                    }

                    else {
                        end= mid - 1;
                    }

                }
            }
        }

        return false;
    }
};