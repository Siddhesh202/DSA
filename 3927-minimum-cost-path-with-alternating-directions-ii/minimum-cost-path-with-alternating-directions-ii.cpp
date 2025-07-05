#define ll long long
class Solution {
public:
    int M, N;
    vector<vector<ll>> dp;

    ll f(int i, int j, vector<vector<int>>& waitCost) {
        if(i == M-1 && j == N-1) return (i+1) * (j+1);
        if(i >= M || j >= N) return LLONG_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        ll entryCost = (i+1) * (j+1);
        ll wait = (i == 0 && j == 0) ? 0 : waitCost[i][j];

        ll right = f(i, j+1, waitCost);
        ll down =  f(i+1, j, waitCost);

        return dp[i][j] = entryCost + wait + min(right, down);
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        M = m, N = n;
        dp.assign(m, vector<ll>(n, -1));
        return f(0, 0, waitCost);    
    }
};