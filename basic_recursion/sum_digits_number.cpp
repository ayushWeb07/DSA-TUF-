// TC- O(log n * log(log n)) | SC- O(log n)
class Solution{
public:

    int sumOfDigits(int n) {
        if (n <= 0) {
            return 0;
        }

        return (n % 10) + sumOfDigits(n / 10);
    }

    int addDigits(int num){
        if(num < 10) {
            return num;
        }

        int sum= sumOfDigits(num);
        return addDigits(sum);
    }
};