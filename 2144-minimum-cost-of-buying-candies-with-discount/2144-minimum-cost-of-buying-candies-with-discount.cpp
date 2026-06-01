class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), ans = 0;

        // sort in desc [9, 7, 6, 5, 2, 2]
        sort(cost.begin(), cost.end(), greater<>());

        for(int i = 0; i < n; i+=3) {
            ans += cost[i];
            if(i+1 < n) ans += cost[i+1];
        }

        return ans;
    }
};