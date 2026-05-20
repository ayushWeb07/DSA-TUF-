// TC- O(n) | SC- O(n)
class Solution{
public:

    vector<char> reverse(vector<char>& s, int st, int end) {
        if(st >= end) {
            return s;
        }

        swap(s[st++], s[end--]);
        return reverse(s, st, end);
    }

    vector<char> reverseString(vector<char>& s){
        int st= 0, end= s.size() - 1;
        return reverse(s, st, end);
    }
};