class Solution{
public:
    vector<char> frequencySort(string& s){
        unordered_map<char, int> charFreq;

        int len= s.size();

        // build the character freq. map
        for(int i=0; i<len; i++) {
            charFreq[s[i]]++;
        }

        vector<pair<char, int>> charFreqVec;

        // build the character freq. map vector
        for (auto &p: charFreq) {
            charFreqVec.push_back({p.first, p.second});
        }

        // sort the vector
        sort(charFreqVec.begin(), charFreqVec.end(), [](const auto& a, const auto& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }

            return a.second > b.second;
        });

        // build the final vector
        vector<char> resVec;

        for (auto &p: charFreqVec) {
            resVec.push_back(p.first);
        }

        return resVec;
    }
};