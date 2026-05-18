#include <iostream>
#include <string.h>
using namespace std;

// approach 1: Bruteforce - TC -> O(n^3) | SC -> O(1)
class Solution1{
public:	
    string largeOddNum(string& s){
        // remove leading 0s
        int st= 0;

        while((st < s.size()) && (s[st] == '0')) {
            st++;
        }

        s= s.substr(st);
        int l= s.size();
        
        for(int w= l; w >= 1; w--) {
            for(int i= 0; i<l; i+=w) {
                string subSt= s.substr(i, w);
                char lastChar= subSt.back();
                int lastCharNum= lastChar - '0';

                if(lastCharNum % 2 != 0) {
                    return subSt;
                }
            }
        }

        return "";
    }
};

// approach 2: Optimal - TC -> O(n) | SC -> O(k) where k is the length of the substring
class Solution2{
public:
    string largeOddNum(string& s){

        int len= s.size();

        // find the index of the first non zero element
        int st= 0;

        while(st < len && s[st] == '0') {
            st++;
        }

        // find the index of first odd element from right
        int end= -1;

        for(int i=len-1; i>=0; i--) {
            char ch= s[i];
            int chNum= ch - '0';

            if(chNum % 2 != 0) {
                end= i;
                break;
            }
        }

        // return the substring
        return end == -1 ? "" : s.substr(st, end - st + 1);
    }
};