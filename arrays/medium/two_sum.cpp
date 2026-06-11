#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n) | SC - O(n)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // prepare a map of element -> index
        unordered_map<int, int> numsMap;
        vector<int> res;
        int curr, rem;

        int size= nums.size();

        // simple traversal
        for(int i=0; i<size; i++) {
            curr= nums[i];
            rem= target - curr;

            if(numsMap.count(rem) > 0) {
                res.push_back(i);
                res.push_back(numsMap[rem]);

                return res;
            } else {
                numsMap[curr]= i;
            }
        }

        return {-1, -1};
    }
};

// TC - O(n log n) | SC - O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size= nums.size();
        int sum;
        int st= 0, end= size - 1;
        vector<pair<int, int>> elementsIndex;
        vector<int> res;

        // prepare the vector with elements and index
        for(int i=0; i<size; i++) {
            elementsIndex.push_back({nums[i], i});
        }

        // sort the array by elements
        sort(elementsIndex.begin(), elementsIndex.end());

        // prepare the resultant vector
        while(st < end) {
            sum= elementsIndex[st].first + elementsIndex[end].first;

            if(sum == target) {
                res.push_back(elementsIndex[st].second);
                res.push_back(elementsIndex[end].second);
                return res;
            }

            else if(sum > target) {
                end--;
            }

            else {
                st++;
            }
        }

        return {-1, -1};
    }
};