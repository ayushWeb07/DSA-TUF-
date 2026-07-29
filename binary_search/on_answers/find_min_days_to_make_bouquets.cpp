#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force -> TC - O(n * m) | SC - O(1)
class Solution1 {
public:
    int roseGarden(int n,vector<int> nums, int k, int m) {
        // handle edge case
        if((m * k) > n) return -1;

        int mini_days= *min_element(nums.begin(), nums.end());
        int maxi_days= *max_element(nums.begin(), nums.end());
        int adjacentBloomedRoses, bouquetsCreated;

        for(int i= mini_days; i<= maxi_days; i++) {
            adjacentBloomedRoses= 0;
            bouquetsCreated= 0;

            for(int j= 0; j< n; j++) {

                if(i >= nums[j]) {
                    adjacentBloomedRoses++;
                }

                else {
                    bouquetsCreated+= adjacentBloomedRoses / k;
                    adjacentBloomedRoses= 0;
                }

            }

            bouquetsCreated+= adjacentBloomedRoses / k;

            if(bouquetsCreated >= m) {
                return i;
            }
        }

        return -1;
    }
};

// optimal -> O(n * log(max(nums) - min(nums))) | SC - O(1)
class Solution2 {
public:
    bool checkIfEnoughBouquetsMade(int n, vector<int> nums, int k, int m, int currentDays) {
        int adjacentBloomedRoses= 0;
        int bouquetsCreated= 0;

        for (int i= 0; i< n; i++) {
            if(currentDays >= nums[i]) {
                adjacentBloomedRoses++;
            }

            else {
                bouquetsCreated+= adjacentBloomedRoses / k;
                adjacentBloomedRoses= 0;
            }
        }

        bouquetsCreated+= adjacentBloomedRoses / k;
        return (bouquetsCreated >= m);
    }

    int roseGarden(int n,vector<int> nums, int k, int m) {
        // handle edge case
        if((m * k) > n) return -1;

        int mini_days= *min_element(nums.begin(), nums.end());
        int maxi_days= *max_element(nums.begin(), nums.end());

        int st= mini_days, end= maxi_days;
        int mid;
        bool check;
        int ans= -1;

        while (st <= end) {
            mid= (st + end) / 2;
            check= checkIfEnoughBouquetsMade(n, nums, k, m, mid);

            if(check) {
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