class Solution{
public:
    string longestCommonPrefix(vector<string>& str){
        // arrange in alphabetic ascending order
        sort(str.begin(), str.end());

        // find the common prefix between first and last string
        string fStr= str.front();
        string lStr= str.back();

        int i= 0;

        while ((i < fStr.size()) && (i < lStr.size()) && (fStr[i] == lStr[i])) {
            i++;
        }

        return fStr.substr(0, i);
    }
};