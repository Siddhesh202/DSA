#define ll long long
#define P pair<long long, long long>
#define MOD 1000000007
class Solution {
public:
    int m,n;
    vector<vector<P>> dp;
    P solve(vector<vector<int>>& grid, int i, int j) {
        if(i == m-1 && j == n-1) return {grid[i][j], grid[i][j]};

        ll minVal = LLONG_MAX, maxVal = LLONG_MIN, elem = grid[i][j];

        if(dp[i][j].first != LLONG_MIN || dp[i][j].second != LLONG_MAX) return dp[i][j];

        // DOWN
        if(i+1 < m) {
            auto [downMax, downMin] = solve(grid, i+1, j);
            maxVal = max({maxVal, elem * downMax, elem * downMin});
            minVal = min({minVal, elem * downMax, elem * downMin});
        }

        // RIGHT
        if(j+1 < n) {
            auto [rightMax, rightMin] = solve(grid, i, j+1);
            maxVal = max({maxVal, elem * rightMax, elem * rightMin});
            minVal = min({minVal, elem * rightMax, elem * rightMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<P>>(m, vector<P>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxVal, minVal] = solve(grid, 0, 0);

        if(maxVal < 0) return -1;
        return maxVal % MOD;
    }
};