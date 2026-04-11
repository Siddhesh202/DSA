class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> lastOccurence;
        int ans = INT_MAX;

        for(int i = cards.size()-1; i >= 0; i--) {
            int card = cards[i];
            if(lastOccurence.count(card)) ans = min(ans, lastOccurence[card] - i + 1);
            lastOccurence[card] = i;
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};