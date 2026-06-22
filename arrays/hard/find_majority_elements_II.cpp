#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(n)
class Solution1 {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        vector<int> res;
        int size= nums.size();
        unordered_map<int, int> numsFreq;

        for(int n: nums) {
            numsFreq[n]++;
        }

        for(auto &p: numsFreq) {
            if(p.second > (size / 3)) {
                res.push_back(p.first);
            }
        }

        return res;
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int len= nums.size();
        vector<int> res;

        int c1= 0, ele1= INT_MIN;
        int c2= 0, ele2= INT_MIN;

        for (int i=0; i<len; i++) {
            if (nums[i] == ele1) {
                c1++;
            }

            else if (nums[i] == ele2) {
                c2++;
            }

            else {
                if ((c1 == 0) && (nums[i] != ele2)) {
                    ele1= nums[i];
                    c1++;
                }

                else if ((c2 == 0) && (nums[i] != ele1)) {
                    ele2= nums[i];
                    c2++;
                }

                else {
                    c1--;
                    c2--;
                }
            }
        }

        c1= 0;
        c2= 0;

        for(int n: nums) {
            if(n == ele1) {
                c1++;
            }

            else if(n == ele2) {
                c2++;
            }
        }

        if(c1 > (len / 3)){
            res.push_back(ele1);
        }

        if(c2 > (len / 3)){
            res.push_back(ele2);
        }

        return res;
    }
};