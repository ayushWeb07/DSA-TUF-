class Solution {
public:
    int sumHighestAndLowestFrequency(vector<int>& nums) {
        map<int, int> freq;
        int maxFreq= INT_MIN, minFreq= INT_MAX;

        for (int ele: nums) {
            freq[ele]++;
        }

        for (auto &p: freq) {
            maxFreq= max(maxFreq, p.second);
            minFreq= min(minFreq, p.second);
        }

        return (maxFreq + minFreq);
    }
};
