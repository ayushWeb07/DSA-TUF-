#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// optimal -> TC - O(m + n) | SC - O(1)
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int m= a.size();
        int n= b.size();
        int tot= m + n;
        k--;

        vector<int> temp;

        int left= 0, right= 0;
        int c= 0, ele= -1;

        while ((left < m) && (right < n)) {
            if (a[left] <= b[right]) {
                if (c == k) return a[left];

                c++;
                left++;
            }

            else {
                if (c == k) return b[right];

                c++;
                right++;
            }
        }

        // left half has exhausted but there are still elements in right half
        while (right < n) {
            if (c == k) return b[right];

            c++;
            right++;
        }

        // right half has exhausted but there are still elements in left half
        while (left < m) {
            if (c == k) return a[left];

            c++;
            left++;
        }
    }
};