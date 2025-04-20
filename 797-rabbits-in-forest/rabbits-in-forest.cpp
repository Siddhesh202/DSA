class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size(), ans = 0;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++)
            mp[answers[i]]++;
        
        for(auto &p : mp) {
            int val = p.second;
            int grpSize = p.first+1;
            if(val < grpSize) ans += grpSize;
            else ans += (ceil(val * 1.0 / grpSize) * grpSize);
        }

        return ans;
    }
};