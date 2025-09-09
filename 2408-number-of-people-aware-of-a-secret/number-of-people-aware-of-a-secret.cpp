class Solution {
public:
    const int MOD = 1000000007;
    int dp[1001];
    int solve(int n, int delay, int forget) {
        if(n <= 0) return 0;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        int l = n - forget + 1;
        int r = n - delay;
        int ans = 0;

        for(int i = l; i <= r; i++) {
            ans = (ans + solve(i, delay, forget)) % MOD;
        }
        

        return dp[n] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        memset(dp, -1, sizeof(dp));
        for(int day = n-forget+1; day <= n; day++) {
            if(day > 0) {
                total = (total + solve(day, delay, forget)) % MOD;
            }
        }

        return total;
    }
};