class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        map<int, int> freq;
        int maxFreq= 0, maxFreqEle= 0;

        for (int ele: nums) {
            freq[ele]++;
        }

        for (auto &p: freq) {
            if(p.second > maxFreq) {
                maxFreq= p.second;
                maxFreqEle= p.first;
            }
        }

        return maxFreqEle;
    }
};