#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(n)
class Solution1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        vector<int> pos;
        vector<int> neg;

        for (int n: nums) {
            if (n > 0) {
                pos.push_back(n);
            } else {
                neg.push_back(n);
            }
        }

        for(int i=0; i<pos.size(); i++) {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }

        return res;
    }
};

// TC - O(n) | SC - O(n)
class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len= nums.size();
        vector<int> temp(len, 0);
        vector<int> res;

        int pIdx= 0, nIdx= len / 2;

        for (int n: nums) {
            if (n > 0) {
                temp[pIdx++]= n;
            } else {
                temp[nIdx++]= n;
            }
        }

        for(int i=0; i<(len / 2); i++) {
            res.push_back(temp[i]);
            res.push_back(temp[i + (len / 2)]);
        }

        return res;
    }
};

// TC - O(n) | SC - O(n)
class Solution3 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx= 0, negIdx= 1;

        vector<int> res(nums.size(), 0);

        for(int n: nums) {
            if(n > 0) {
                res[posIdx]= n;
                posIdx+= 2;
            } else {
                res[negIdx]= n;
                negIdx+= 2;
            }
        }

        return res;
    }
};