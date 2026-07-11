#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(1)
class Solution1{
public:
    int longestSubarray(vector<int> &nums, int k){
        int max_len= INT_MIN;
        int size= nums.size();
        int s, len;

        for(int i= 0; i< size; i++) {
            s= 0;

            for(int j= i; j< size; j++) {
                s+= nums[j];

                if(s == k) {
                    len= (j - i) + 1;
                    max_len= max(max_len, len);
                }
            }
        }

        max_len= max(max_len, 0);

        return max_len;
    }
};

// TC - O(n) | SC - O(n)
class Solution2{
public:
    int longestSubarray(vector<int> &nums, int k){
        int size= nums.size();
        unordered_map<int, int> sums_freq;

        int s= 0;
        int max_len= INT_MIN;
        int len= -1;
        int rem_sum= -1;

        for(int i= 0 ; i< size; i++) {
            s+= nums[i];

            if (s == k) {
                len= i + 1;
                max_len= max(max_len, len);
            }

            else {
                rem_sum= s - k;

                if(sums_freq.find(rem_sum) != sums_freq.end()) {
                    len= i - sums_freq[rem_sum];
                    max_len= max(max_len, len);
                }
            }

            if(sums_freq.find(s) != sums_freq.end()) {
                sums_freq[s]= min(sums_freq[s], i);
            } else {
                sums_freq[s]= i;
            }
        }

        max_len= max(max_len, 0);

        return max_len;
    }
};
