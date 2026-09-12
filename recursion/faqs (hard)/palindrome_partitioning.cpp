#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n * 2^n) | SC - O(n)
class Solution {
public:
    bool isPalindrome(string& w, int st, int end) {
        if (st >= end) {
            return true;
        }

        if (w[st] != w[end]) {
            return false;
        }

        return isPalindrome(w, st + 1, end - 1);
    }

    void buildAns(string& st, int n, int i, vector<string>& lst, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(lst);
            return;
        }

        for (int j= i; j < n; j++) {
            // check if substring from i -> j, is palindrome
            bool isP= isPalindrome(st, i, j);

            if (isP) {
                lst.push_back(st.substr(i, j - i + 1));
                buildAns(st, n, j + 1, lst, ans);
                lst.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n= s.size();
        vector<vector<string>> ans;
        vector<string> lst;

        buildAns(s, n, 0, lst, ans);

        return ans;
    }
};