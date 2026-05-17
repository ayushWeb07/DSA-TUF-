class Solution {
public:
    int secondMostFrequentElement(vector<int>& nums) {
        map<int, int> freq;
        int maxFreq= 0, maxFreqEle= 0;
        int secondMaxFreq= 0, secondMaxFreqEle= 0;

        for (int ele: nums) {
            freq[ele]+= 1;
        }

        for (auto &p: freq) {
            if(p.second > maxFreq) {
                maxFreq= p.second;
                maxFreqEle= p.first;
            }
        }

        for (auto &p: freq) {
            if((p.second > secondMaxFreq) && (p.second < maxFreq) ) {
                secondMaxFreq= p.second;
                secondMaxFreqEle= p.first;
            }
        }

        return secondMaxFreqEle == 0 ? -1 : secondMaxFreqEle;
    }
};