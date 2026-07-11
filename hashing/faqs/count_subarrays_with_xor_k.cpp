#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(1)
class Solution1{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int size= nums.size();
        int cnt= 0;
        int xorr= 0;

        for(int i= 0; i< size; i++) {
            xorr= 0;

            for(int j= i; j< size; j++) {
                xorr= xorr ^ nums[j];

                if(xorr == k) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// TC - O(n) | SC - O(n)
class Solution2{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int size= nums.size();
        int cnt= 0;
        int tot_xor= 0;
        unordered_map<int, int> xor_freq;
        int rem_xor;

        xor_freq[0]= 1;

        for(int i= 0; i< size; i++) {
            tot_xor= tot_xor ^ nums[i];

            rem_xor= tot_xor ^ k;

            cnt+= xor_freq[rem_xor];

            xor_freq[tot_xor]++;
        }

        return cnt;
    }
};