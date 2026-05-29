#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O((n+m) log(n+m)) | SC - O(n+m)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> temp;
        int len1= nums1.size();
        int len2= nums2.size();

        int i= 0, j= 0;

        while((i < len1) && (j < len2)) {
            if(nums1[i] <= nums2[j]) {
                temp.insert(nums1[i++]);
            }

            else {
                temp.insert(nums2[j++]);
            }
        }

        while(j < len2) {
            temp.insert(nums2[j++]);
        }

        while(i < len1) {
            temp.insert(nums1[i++]);
        }

        vector<int> vec(temp.begin(), temp.end());

        return vec;
    }
};