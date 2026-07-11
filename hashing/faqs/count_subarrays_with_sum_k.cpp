#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(1)
class Solution1{
public:
    int subarraySum(vector<int> &nums, int k){
        int cnt= 0;
        int size= nums.size();
        int s, len;

        for(int i= 0; i< size; i++) {
            s= 0;

            for(int j= i; j< size; j++) {
                s+= nums[j];

                if(s == k) {
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
    int subarraySum(vector<int> &nums, int k){
        int size= nums.size();
        unordered_map<int, int> sums_freq;
        int cnt= 0, s= 0;
        int rem_part;

        sums_freq[0]= 1;

        for(int i= 0; i< size; i++) {
            s+= nums[i];

            rem_part= s - k;

            cnt+= sums_freq[rem_part];

            sums_freq[s]++;
        }

        return cnt;
    }
};