class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int> mp;
        int maxfreq = INT_MIN;
        string ans = "";

        for(auto &resp : responses) {
            unordered_set<string> st;
            for(auto str : resp) st.insert(str);

            for(auto &str : st) mp[str]++;
        }

        for(auto &p : mp)
        {
            if(p.second > maxfreq) {
                maxfreq = p.second;
                ans = p.first;
            }
            else if(p.second == maxfreq) {
                ans = lexicographical_compare(p.first.begin(),p.first.end(), ans.begin(), ans.end()) ? p.first : ans;
            }
        }

        return ans;
    }
};