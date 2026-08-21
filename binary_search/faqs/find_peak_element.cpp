#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(log n) | SC - O(1)
class Solution {
public:
    int findPeakElement(vector<int> &arr) {
        int size= arr.size();

        // handle single element
        if (size == 1) return 0;

        // handle the first element
        if (arr[0] > arr[1]) return 0;

        // handle the last element
        if (arr[size - 1] > arr[size - 2]) return size - 1;

        int st= 1, end= size - 2;
        int mid;

        while (st <= end) {
            mid= (st + end) / 2;

            if((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1])) return mid;

            else if (arr[mid] < arr[mid + 1]) {
                st= mid + 1;
            }

            else {
                end= mid - 1;
            }
        }

        return -1;
    }
};