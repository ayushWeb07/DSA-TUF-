#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(3^(n^2)) | SC - O(n^2)
class Solution{
public:
    void buildAns(vector<vector<int>> &grid, int& n, int i, int j, string st, vector<string>& ans) {
        // OOB check
        if ((i < 0) || (j < 0) || (i == n) || (j == n)) {
            return;
        }

        // zero check
        if (grid[i][j] == 0) {
            return;
        }

        if ((i == (n - 1)) && (j == (n - 1))) {
            ans.push_back(st);
            return;
        }

        // put 0 in the current cell
        grid[i][j]= 0;

        // traverse top
        buildAns(grid, n, i - 1, j, st + 'U', ans);

        // traverse right
        buildAns(grid, n, i, j + 1, st + 'R', ans);

        // traverse bottom
        buildAns(grid, n, i + 1, j, st + 'D', ans);

        // traverse left
        buildAns(grid, n, i, j - 1, st + 'L', ans);

        // put back 1 in the current cell
        grid[i][j]= 1;
    }

    vector<string> findPath(vector<vector<int>> &grid) {
        vector<string> ans;
        string st= "";
        int n= grid.size();

        buildAns(grid, n, 0, 0, st, ans);

        return ans;
    }
};