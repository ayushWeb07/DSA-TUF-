#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2) | SC - O(1)
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int size= nums.size();
        int maxi_prod= INT_MIN;
        int prod;

        for(int i= 0; i< size; i++) {
            prod= 1;

            for(int j= i; j< size; j++) {
                prod*= nums[j];
                maxi_prod= max(maxi_prod, prod);
            }
        }

        return maxi_prod;
    }
};

// TC - O(n) | SC - O(1)
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int size= nums.size();
        int prefix_prod= 1, suffix_prod= 1;
        int junc_prod;
        int maxi_prod= INT_MIN;

        for(int i= 0; i< size; i++) {
            // reset the prods if they are zero
            if(prefix_prod == 0) {
                prefix_prod= 1;
            }

            if(suffix_prod == 0) {
                suffix_prod= 1;
            }

            // calc the prods
            prefix_prod*= nums[i];
            suffix_prod*= nums[(size - 1) - i];

            // find the max prod for this junction / element
            junc_prod= max(prefix_prod, suffix_prod);
            maxi_prod= max(maxi_prod, junc_prod);
        }

        return maxi_prod;
    }
};