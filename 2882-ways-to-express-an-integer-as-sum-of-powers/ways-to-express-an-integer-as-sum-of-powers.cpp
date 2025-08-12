#define ll long long
#define MOD 1000000007
class Solution {
public:
    vector<vector<int>> dp;
    ll intPow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            res *= base;
            exp--;
        }
        return res;
    }

    ll f(ll n, ll x, ll num, ll sum) {
        if(sum == n) return 1;
        if(sum > n) return 0;
        if(num > n) return 0;
        
        ll power = intPow(num, x);
        // if (power > n - sum) return 0;

        if(dp[num][sum] != -1) return dp[num][sum];

        // take
        ll take = f(n, x, num+1, sum+power) % MOD;

        // no take
        ll notake = f(n, x, num+1, sum) % MOD;

        return dp[num][sum] = (take + notake) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n+1, vector<int> (n+1, -1));
        return f(n, x, 1, 0);
    }
};