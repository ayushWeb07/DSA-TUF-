// TC- O(n) | SC- O(n)
class Solution{
public:
    int sum(int n) {
        if(n == 0) {
            return 0;
        }

        return n + sum(n-1);
    }
    int NnumbersSum(int N){
        return sum(N);
    }
};