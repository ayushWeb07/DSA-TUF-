#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(m + n) | SC - O(1)
class Solution {
public:
    double calcMedian(int total, int ele1, int ele2) {
        if (total % 2 == 1) {
            return ele1;
        }

        else {
            return ((double)ele1 + ele2) / 2;
        }
    }

    double median(vector<int> &arr1, vector<int> &arr2) {
        int m= arr1.size();
        int n= arr2.size();
        int tot= m + n;

        vector<int> temp;

        int left= 0, right= 0;
        int c= 0, ele1= -1, ele2= -1;
        int ind1= tot / 2;
        int ind2= (tot / 2) - 1;

        while ((left < m) && (right < n)) {
            if (arr1[left] <= arr2[right]) {
                if (c == ind2) ele2= arr1[left];
                else if (c == ind1) ele1= arr1[left];

                c++;
                left++;
            }

            else {
                if (c == ind2) ele2= arr2[right];
                else if (c == ind1) ele1= arr2[right];

                c++;
                right++;
            }
        }

        if((ele1 == -1) || (ele2 == -1)) {
            // left half has exhausted but there are still elements in right half
            while (right < n) {
                if (c == ind2) ele2= arr2[right];
                else if (c == ind1) ele1= arr2[right];

                c++;
                right++;
            }

            // right half has exhausted but there are still elements in left half
            while (left < m) {
                if (c == ind2) ele2= arr1[left];
                else if (c == ind1) ele1= arr1[left];

                c++;
                left++;
            }
        }

        return calcMedian(tot, ele1, ele2);
    }
};