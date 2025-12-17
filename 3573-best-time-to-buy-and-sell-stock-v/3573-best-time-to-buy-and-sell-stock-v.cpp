#define ll long long
class Solution {
public:
    int n;
    ll solve(int i, int k, vector<int>& prices, int CASE, vector<vector<vector<ll>>> &dp) {
        if(i == n) {
            if(CASE == 0) return 0;
            return LLONG_MIN / 2;
        }

        if(dp[i][k][CASE] != -1) return dp[i][k][CASE];

        ll notake = solve(i+1, k, prices, CASE, dp);
        ll take = LLONG_MIN / 2;

        if(k > 0) {
            if(CASE == 0) {
                take = max(-1 * prices[i] + solve(i+1, k, prices, 1, dp), 
                        prices[i] + solve(i+1, k, prices, 2, dp));
            }
            else if(CASE == 1) {
                take = prices[i] + solve(i+1, k-1, prices, 0, dp);
            }
            else {
                take = -1 * prices[i] + solve(i+1, k-1, prices, 0, dp);
            }
        }

        return dp[i][k][CASE] = max(take, notake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(3, -1)));
        return solve(0, k, prices, 0, dp);
    }
};