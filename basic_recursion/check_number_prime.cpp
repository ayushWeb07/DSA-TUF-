// TC- O(sqrt(n)) | SC- O(sqrt(n))
class Solution{
public:
    bool check(int num, int f) {
        if(f*f > num) {
            return true;
        }

        if(num % f == 0) {
            return false;
        }

        return check(num, f+1);
    }

    bool checkPrime(int num){
        if(num == 1) {
            return false;
        }

        return check(num, 2);
    }
};