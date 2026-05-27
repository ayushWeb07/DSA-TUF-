#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int maxEle= INT_MIN;
        int secMaxEle= INT_MIN;

        for(int ele: nums) {
            if(ele > maxEle) {
                secMaxEle= maxEle;
                maxEle= ele; 
            }

            if(ele > secMaxEle && ele < maxEle) {
                secMaxEle= ele;
            }
        }

        return secMaxEle == INT_MIN ? -1 : secMaxEle;
    }
};