#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(n)
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size= nums.size();
        unordered_map<int, int> numsFreq;
        unordered_map<int, int> numsIndex;
        set<vector<int>> res;

        if(size <= 2) {
            return {};
        }

        // prepare the numbers frequency
        for(int i=0; i<size; i++) {
            numsFreq[nums[i]]++;
            numsIndex[nums[i]]= i;
        }

        for(int i=0; i <= (size - 2); i++) {
            for(int j= (i + 1); j <= (size - 1); j++) {
                int sum= nums[i] + nums[j];
                int oppo= -1 * sum;

                auto it = numsIndex.find(oppo);

                if((numsFreq[oppo] > 0) && (it != numsIndex.end()) && (i != j) && (j != numsIndex[oppo]) && (numsIndex[oppo] != i)) {
                    vector<int> ans;

                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(oppo);

                    sort(ans.begin(), ans.end());
                    res.insert(ans);
                }
            }
        }

        vector<vector<int>> resVector(res.begin(), res.end());

        return resVector;

    }
};

// TC - O(n^2) | SC - O(k) where k -> no. of unique triplets
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resMat;

        // sort the vector
        sort(nums.begin(), nums.end());

        // two pointer approach
        int size= nums.size();
        int st, end;

        if(size <= 2) {
            return {};
        }

        for(int i=0; i<= (size - 3); i++) {
            if((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            st= (i + 1);
            end= size - 1;

            while (st < end) {
                int sum= nums[i] + nums[st] + nums[end];

                if(sum > 0) {
                    end--;
                }

                else if(sum < 0) {
                    st++;
                }

                else {
                    vector<int> resVec= {nums[i], nums[st], nums[end]};
                    resMat.push_back(resVec);

                    st++;
                    end--;

                    while((st < end) && (nums[st] == nums[st - 1])) {
                        st++;
                    }

                    while((st < end) && (nums[end] == nums[end + 1])) {
                        end--;
                    }
                }
            }
        }

        return resMat;
    }
};