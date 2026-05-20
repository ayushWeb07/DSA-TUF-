// TC- O(n) | SC- O(n)
class Solution{
public:
    int sum(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            return 0;
        }

        return nums[idx] + sum(nums, idx + 1);
    }

    int arraySum(vector<int>& nums){
        return sum(nums, 0);
    }
};