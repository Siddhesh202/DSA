class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> mp;
        int ans = INT_MAX;

        for(int i = 0; i < cards.size(); i++) mp[cards[i]].push_back(i);

        for(auto &[card, arr] : mp) {
            if(arr.size() >= 2) {
                for(int i = 0; i < arr.size()-1; i++) ans = min(ans, arr[i+1] - arr[i]+1);
            }
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};