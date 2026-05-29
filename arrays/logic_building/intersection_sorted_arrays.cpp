#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n + m) | SC - O(min(n, m))
class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int len1= nums1.size();
        int len2= nums2.size();

        int i= 0, j= 0;

        while((i < len1) && (j < len2)) {
            if(nums1[i] < nums2[j]) {
                i++;
            }

            else if(nums2[j] < nums1[i]) {
                j++;
            }

            else {
                temp.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return temp;
    }
};