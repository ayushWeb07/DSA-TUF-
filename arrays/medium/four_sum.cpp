#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^3 * log(k)) | SC - O(n)
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size= nums.size();
        unordered_map<int, int> numsFreq;
        unordered_map<int, int> numsIndex;
        set<vector<int>> res;

        if(size <= 3) {
            return {};
        }

        // prepare the numbers frequency
        for(int i=0; i<size; i++) {
            numsFreq[nums[i]]++;
            numsIndex[nums[i]]= i;
        }

        for(int i=0; i <= (size - 3); i++) {
            for(int j= (i + 1); j <= (size - 2); j++) {
                for(int k= (j + 1); k <= (size - 1); k++) {
                    int sum= nums[i] + nums[j] + nums[k];
                    int oppo= target - sum;

                    auto it = numsIndex.find(oppo);

                    if((numsFreq[oppo] > 0) && (it != numsIndex.end()) && (i != j) && (j != k) && (j != numsIndex[oppo]) && (k != numsIndex[oppo]) && (k != i) && (numsIndex[oppo] != i)) {
                        vector<int> ans;

                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ans.push_back(oppo);

                        sort(ans.begin(), ans.end());
                        res.insert(ans);
                    }
                }
            }
        }

        vector<vector<int>> resVector(res.begin(), res.end());

        return resVector;
    }
};

// TC - O(n^3) | SC - O(1)
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> resMat;

        // sort the vector
        sort(nums.begin(), nums.end());

        // two pointer approach
        int size= nums.size();
        int st, end;

        if(size <= 3) {
            return {};
        }

        for(int i=0; i<= (size - 4); i++) {
            if((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            for(int j= (i + 1); j<= (size - 3); j++) {
                if((j > (i + 1)) && (nums[j] == nums[j - 1])) {
                    continue;
                }

                st= (j + 1);
                end= size - 1;

                while (st < end) {
                    int sum= nums[i] + nums[j] + nums[st] + nums[end];

                    if(sum > target) {
                        end--;
                    }

                    else if(sum < target) {
                        st++;
                    }

                    else {
                        vector<int> resVec= {nums[i], nums[j], nums[st], nums[end]};
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
        }

        return resMat;
    }
};