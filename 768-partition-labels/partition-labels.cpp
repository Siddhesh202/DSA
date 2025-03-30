class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int start = 0, impact = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < s.length(); i++)
            mp[s[i]] = i;
        
        for(int i = 0; i < s.length(); i++) {
            impact = max(impact, mp[s[i]]);

            if(impact == i) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};