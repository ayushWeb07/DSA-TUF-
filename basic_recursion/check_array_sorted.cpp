// TC- O(n) | SC- O(n)
class Solution{
public:
    bool check(vector<int>& nums, int st, int end) {
        if(st >= end) {
            return true;
        }

        if(nums[st] > nums[st+1]) {
            return false;
        }

        return check(nums, st+1, end);
    }

    bool isSorted(vector<int>& nums){
        int st= 0, end= nums.size() - 1;
        return check(nums, st, end);
    }
};