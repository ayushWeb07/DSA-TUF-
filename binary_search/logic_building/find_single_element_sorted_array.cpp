#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int size= nums.size();
        int st= 0, end= size - 1;
        int mid;

        // if array has just single element
        if(size == 1) {
            return nums[0];
        }

        // check if first element is single
        if(nums[st] != nums[st + 1]) {
            return nums[st];
        }

        // check if last element is single
        if(nums[end] != nums[end - 1]) {
            return nums[end];
        }

        // trim the limits as we already handled the cases for st and end
        st++;
        end--;

        while (st <= end) {
            mid= (st + end) / 2;

            // check if element at mid, is single
            if((nums[mid - 1] != nums[mid]) && (nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            else {

                // check if single element lies in the right half, so that we can eliminate the left half
                if((mid % 2 == 0) && (nums[mid] == nums[mid + 1]) ||
                   (mid % 2 == 1) && (nums[mid] == nums[mid - 1])) {

                    st= mid + 1;

                   }

                // single element lies in the left half, so just eliminate the right half
                else {
                    end= mid - 1;
                }

            }
        }

        return -1;
    }
};
