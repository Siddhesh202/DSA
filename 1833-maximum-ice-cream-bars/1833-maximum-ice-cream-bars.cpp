class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;

        for(auto &cost: costs) {
            if(cost <= coins) {
                ans++;
                coins -= cost;
            }
            else break;
        }

        return ans;
    }
};