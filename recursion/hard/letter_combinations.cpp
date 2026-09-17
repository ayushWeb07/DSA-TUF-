#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(4 ^ n * n) | SC - O(n)
class Solution {
public:
    void buildAns(string digits, int n, map<char, string>& lettersMap, int i, string w, vector<string>& ans) {
        if (i == n) {
            ans.push_back(w);
            return;
        }

        // get the letters mapping
        string chrs= lettersMap[digits[i]];

        for (char ch: chrs) {
            // take the current one
            buildAns(digits, n, lettersMap, i + 1, w + ch, ans);
        }
    }


    vector<string> letterCombinations(string digits) {
        // create the map of letters with string
        map<char, string> lettersMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        int n= digits.size();
        vector<string> ans;

        buildAns(digits, n, lettersMap, 0, "", ans);

        return ans;
    }
};