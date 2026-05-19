// approach 1: Bruteforce approach
class Solution1{
public:
    bool rotateString(string& s,string& goal){
        if(s == goal) {
            return true;
        }

        string temp= s;
        int len= s.size();

        for(int i=1; i<len; i++) {
            temp= temp.substr(1, len-1) + temp[0];

            if(temp == goal) {
                return true;
            }
        }

        return false;
    }
};

// approach 2: optimal approach
class Solution2{
public:
    bool rotateString(string& s,string& goal){
        if (s == goal) {
            return true;
        }

        if(s.size() != goal.size()) {
            return false;
        }

        string t= s + s; // concat the strings one after another

        return t.find(goal) != string::npos;
    }
};