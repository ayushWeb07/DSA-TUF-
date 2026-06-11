#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(n)
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numsFreq;
        int len= nums.size();
        int majorEle= -1, majorEleFreq= 0;

        // create the numbers freq
        for(int ele: nums) {
            numsFreq[ele]++;
        }

        for(auto &p: numsFreq) {
            if(p.second > majorEleFreq) {
                majorEle= p.first;
                majorEleFreq= p.second;
            } 
        }

        return majorEle;
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int len= nums.size();

        int c= 1, ele= nums[0];

        for (int i=1; i<len; i++) {
            if (nums[i] == ele) {
                c++;
            }

            else {
                if (c == 0) {
                    ele= nums[i];
                    c++;
                }

                else {
                    c--;
                }
            }
        }

        return ele;
    }
};