#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(n)
class Solution1 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int> res;
        int n= nums.size();

        // calc the expected sum
        int expSum= (n * (n + 1)) / 2;

        // calc the actual sum
        int actSum= 0;

        for(int n: nums) {
            actSum+= n;
        }

        // calc the drift
        int drift= expSum - actSum;

        // find a
        unordered_map<int, int> numsFreq;
        int a= -1;

        for(int n: nums) {
            numsFreq[n]++;

            if(numsFreq[n] == 2) {
                a= n;
                break;
            }
        }

        // find b
        int b= drift + a;

        return {a, b};
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int> res;
        int n= nums.size();

        // calc the expected sum
        int expSum= (n * (n + 1)) / 2;

        // calc the actual sum
        int actSum= 0;

        for(int n: nums) {
            actSum+= n;
        }

        // calc the drift
        int drift= expSum - actSum;

        // b - a = expSum - actSum a.k.a. drift

        // calc the sum of squares
        int actSumSquares= 0, expSumSquares= 0;

        for(int n: nums) {
            actSumSquares+= (n * n);
        }

        for(int i= 1; i<= n; i++) {
            expSumSquares+= (i * i);
        }

        // calc the drift of square
        int driftSquares= expSumSquares - actSumSquares;

        // calc the driftSquares / drift
        int divi= driftSquares / drift;

        // calc b and a
        int b= (divi + drift) / 2;
        int a= divi - b;

        return {a, b};
    }
};