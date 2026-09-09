#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(4^n / sqrt(n)) | SC - O(n)
class Solution {
public:
    void p(int n, vector<string>& res, string s, int o, int c) {
        if (o > n) {
            return;
        }

        if ((o == c) && (o == n)) {
            res.push_back(s);
            return;
        }

        // explore opening brackets
        p(n, res, s + '(', o + 1, c);

        // explore closing brackets
        if (o > c) {
            p(n, res, s + ')', o, c + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s= "(";

        p(n, res, s, 1, 0);

        return res;
    }
};