class Solution{
public:
    bool anagramStrings(string& s,string t){
        if(s == t) {
            return true;
        }

        int sLen= s.size();
        int tLen= t.size();

        if(sLen != tLen) {
            return false;
        }

        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;

        // build the freq. map of s and t
        for(int i=0; i<sLen; i++) {
            sFreq[s[i]]++;
            tFreq[t[i]]++;
        }

        return sFreq == tFreq;
    }
};