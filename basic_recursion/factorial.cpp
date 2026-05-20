// TC- O(n) | SC- O(n)
class Solution{
public:
    long long int factorial(int n){
        if(n == 0 || n == 1) {
            return 1;
        }

        return n * factorial(n-1);
    }
};