#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n log n) | SC - O(log n)
class Solution1 {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int size= nums.size();
        unordered_map<int, int> freq;

        // prepare the freq. map
        for(int n: nums) {
            freq[n]++;
        }

        int zeroFreq= freq[0];
        int oneFreq= freq[1];
        int twoFreq= freq[2];

        // put the 0s
        for(int i=0; i<zeroFreq; i++) {
            nums[i]= 0;
        }

        // put the 1s
        for(int i=zeroFreq; i<zeroFreq + oneFreq; i++) {
            nums[i]= 1;
        }

        // put the 2s
        for(int i=zeroFreq + oneFreq; i<zeroFreq + oneFreq + twoFreq; i++) {
            nums[i]= 2;
        }
    }
};