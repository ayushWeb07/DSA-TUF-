#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n log n) | SC - O(n)
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        for(int ele: nums) {
            st.insert(ele);
        }

        int uniqueCt= st.size();

        int i= 0;

        for(int ele: st) {
            nums[i++]= ele;
        }

        return uniqueCt;
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int len= nums.size();

        int i= 0, j= 1;

        while (j < len) {
            if (nums[i] != nums[j]) {
                nums[i+1]= nums[j];
                i++;
            }

            j++;
        }

        return i+1;
    }
};