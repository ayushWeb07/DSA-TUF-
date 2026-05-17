class Solution{
public:
    bool palindromeCheck(string& s){
        //your code goes here
        int st= 0, end= s.size() - 1;

        while(st < end) {
            if(s[st++] != s[end--]) {
                return false;
            }
        }

        return true;
    }
};