class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size(), ans = 0;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++)
            mp[answers[i]]++;
        
        for(auto &p : mp) {
            int key = p.first;
            int val = p.second;

            cout << key << endl;
            
            int grpSize = key+1;
            if(val < grpSize) ans += grpSize;

            else {
                ans += (ceil(val * 1.0 / grpSize) * grpSize);
            }
        }

        return ans;
    }
};