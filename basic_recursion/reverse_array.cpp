// TC- O(n) | SC- O(n)
class Solution{
public:
    vector<int> reverse(vector<int>& nums, int st, int end) {
        if(st >= end) {
            return nums;
        }

        swap(nums[st++], nums[end--]);
        return reverse(nums, st, end);
    }

    vector<int> reverseArray(vector<int>& nums){
        int st= 0, end= nums.size() - 1;
        return reverse(nums, st, end);
    }
};