class Solution {
public:
    bool isomorphicString(string s, string t) {
        unordered_map<char, char> s_t; // s: key, t: value
        unordered_map<char, char> t_s; // t: key, s: value

        int sLen= s.size();
        int tLen= t.size();

        if(sLen != tLen) {
            return false;
        }

        for(int i=0; i<sLen; i++) {
            char sCh= s[i]; 
            char tCh= t[i]; 

            if((s_t.count(sCh) && s_t[sCh] != tCh) || (t_s.count(tCh) && t_s[tCh] != sCh)) {
                return false;
            }
            
            s_t[sCh]= tCh;
            t_s[tCh]= sCh;
        }

        return true;
    }
};