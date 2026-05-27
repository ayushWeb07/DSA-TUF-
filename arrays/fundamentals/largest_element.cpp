#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxEle= INT_MIN;

        for(int ele: nums) {
            maxEle= max(maxEle, ele);
        }

        return maxEle;
    }
};