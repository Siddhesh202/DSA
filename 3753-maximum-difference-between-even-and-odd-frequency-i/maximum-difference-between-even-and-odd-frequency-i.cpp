class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        int minEvenFreq = INT_MAX, maxOddFreq = 0;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            mp[ch]++;
        }

        for(auto &p : mp) {
            char ch = p.first;
            int freq = p.second;

            if(freq % 2 == 0) { // even freq
                minEvenFreq = min(minEvenFreq, freq);
            }
            else { // odd freq
                maxOddFreq = max(maxOddFreq, freq);
            }
        }

        return maxOddFreq - minEvenFreq;
    }
};