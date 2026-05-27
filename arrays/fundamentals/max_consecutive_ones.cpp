#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCt= 0, ct= 0;

        for(int ele: nums) {
            if(ele == 1) {
                ct++; 
                maxCt= max(maxCt, ct);
            }

            else {
                ct= 0;
            }
        }

        return maxCt;
    }
};