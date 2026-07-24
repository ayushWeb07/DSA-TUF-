#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(log n) | SC - O(1)
class Solution {
public:
    int findMin(vector<int> &arr)  {
        int size= arr.size();
        int st= 0, end= size - 1;
        int mid;
        int mini= INT_MAX;

        while (st <= end) {
            mid= (st + end) / 2;

            mini= min(mini, arr[mid]);

            // check if left half is sorted
            if(arr[st] <= arr[mid]) {
                mini= min(mini, arr[st]);
                st= mid + 1;
            }

            // right half is sorted
            else {
                mini= min(mini, arr[mid]);
                end= mid - 1;
            }

        }

        return mini;
    }
};