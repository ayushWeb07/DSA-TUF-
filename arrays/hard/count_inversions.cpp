#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(1)
class Solution1 {
public:
    long long int numberOfInversions(vector<int> nums) {
        long long int cnt= 0;
        int size= nums.size();

        for(int i=0; i<= (size - 2); i++) {
            for(int j= (i + 1); j<= (size - 1); j++) {
                if(nums[i] > nums[j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// TC - O(n log n) | SC - O(n)
class Solution2 {
public:
    void merge(vector<int>& nums, int st, int mid, int end, long long int& cnt) {
        int left= st; // start of left half
        int right= mid + 1; // start of right half
        vector<int> temp;

        while ((left <= mid) && (right <= end)) {
            if(nums[left] > nums[right]) {
                cnt+= ((mid - left) + 1);
                temp.push_back(nums[right++]);
            }

            else {
                temp.push_back(nums[left++]);
            }
        }

        // left half has exhausted but there are still elements in right half
        while (right <= end) {
            temp.push_back(nums[right++]);
        }

        // right half has exhausted but there are still elements in left half
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        // put all elements from the temp back to org array
        for (int i= st; i<=end; i++) {
            nums[i]= temp[i - st];
        }
    }

    void mS(vector<int>& nums, int st, int end, long long int& cnt) {
        if (st >= end) {
            return;
        }

        // find the mid index
        int mid= (st + end) / 2;

        // divide the left half: st -> mid
        mS(nums, st, mid, cnt);

        // divide the right half: mid + 1 -> end
        mS(nums, mid + 1, end, cnt);

        // merge both the halfs
        merge(nums, st, mid, end, cnt);
    }

    void mergeSort(vector<int>& nums, long long int& cnt) {
        int st= 0;
        int end= nums.size() - 1;

        mS(nums, st, end, cnt);
    }

    long long int numberOfInversions(vector<int> nums) {
        long long int cnt= 0;
        mergeSort(nums, cnt);
        return cnt;
    }
};