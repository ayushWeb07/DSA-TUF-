#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(N log N + N log M) | SC - O(1)
class Solution {
public:
    bool checkValidConfig(vector<int> &nums, int k, int size, int minDist) {

        if(k > size) {
            return false;
        }

        int cowsAss= 1, lastIns= nums[0];
        int dist;

        for (int i= 1; i< size; i++) {
            dist= nums[i] - lastIns;

            if (dist >= minDist) {
                cowsAss++;
                lastIns= nums[i];
            }

            if(cowsAss >= k) {
                return true;
            }
        }

        return (cowsAss >= k);
    }


    int aggressiveCows(vector<int> &nums, int k) {
        int size= nums.size();

        // sort the coors.
        sort(nums.begin(), nums.end());

        int st= 1, end= nums[size - 1] - nums[0];
        int mid;

        int maxMinDist= 0;

        while (st <= end) {
            mid= (st + end) / 2;

            if(checkValidConfig(nums, k, size, mid)) {
                maxMinDist= mid;
                st= mid + 1;
            }

            else {
                end= mid - 1;
            }
        }

        return maxMinDist;
    }
};