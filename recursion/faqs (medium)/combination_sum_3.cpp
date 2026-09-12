#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(2 ^ 9) | SC - O(k)
class Solution {
public:
    void buildAns(int n, int k, int i, int s, vector<int>& lst, vector<vector<int>>& ans) {

        if ((lst.size() == k) && (s == n)) {
            ans.push_back(lst);
            return;
        }

        if ((s > n) || (lst.size() > k) || (i > 9)) {
            return;
        }

        // take the current one
        lst.push_back(i);
        buildAns(n, k, i + 1, s + i, lst, ans);
        lst.pop_back();

        // do not take the current one
        buildAns(n, k, i + 1, s, lst, ans);
    }

    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> lst;
        vector<vector<int>> ans;

        buildAns(n, k, 1, 0, lst, ans);

        return ans;
    }
};