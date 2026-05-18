class Solution{	
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