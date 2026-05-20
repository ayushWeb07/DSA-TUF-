// TC- O(n) | SC- O(n)
class Solution{
public:
    bool check(string& s, int st, int end) {
        if(st >= end) {
            return true;
        }

        if(s[st++] != s[end--]) {
            return false;
        }

        return check(s, st, end);
    }

    bool palindromeCheck(string& s){
        int st= 0, end= s.size() - 1;
        return check(s, st, end);
    }
};