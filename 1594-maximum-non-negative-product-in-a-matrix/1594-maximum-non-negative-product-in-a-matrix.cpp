#define ll long long
#define P pair<long long, long long>
#define MOD 1000000007
class Solution {
public:
    int m,n;
    // vector<vector<P>> dp;
    // P solve(vector<vector<int>>& grid, int i, int j) {
    //     if(i == m-1 && j == n-1) return {grid[i][j], grid[i][j]};

    //     ll minVal = LLONG_MAX, maxVal = LLONG_MIN, elem = grid[i][j];

    //     if(dp[i][j].first != LLONG_MIN || dp[i][j].second != LLONG_MAX) return dp[i][j];

    //     // DOWN
    //     if(i+1 < m) {
    //         auto [downMax, downMin] = solve(grid, i+1, j);
    //         maxVal = max({maxVal, elem * downMax, elem * downMin});
    //         minVal = min({minVal, elem * downMax, elem * downMin});
    //     }

    //     // RIGHT
    //     if(j+1 < n) {
    //         auto [rightMax, rightMin] = solve(grid, i, j+1);
    //         maxVal = max({maxVal, elem * rightMax, elem * rightMin});
    //         minVal = min({minVal, elem * rightMax, elem * rightMin});
    //     }

    //     return dp[i][j] = {maxVal, minVal};
    // }

    P tab(vector<vector<int>>& grid) {
        vector<vector<P>> dp(m, vector<P>(n, {LLONG_MIN, LLONG_MAX}));

        // Base case
        dp[m-1][n-1] = {grid[m-1][n-1], grid[m-1][n-1]};

        // loop on i and j
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(i == m-1 && j == n-1) continue;

                ll minVal = LLONG_MAX, maxVal = LLONG_MIN, elem = grid[i][j];

                // DOWN
                if(i+1 < m) {
                    auto [downMax, downMin] = dp[i+1][j];
                    maxVal = max({maxVal, elem * downMax, elem * downMin});
                    minVal = min({minVal, elem * downMax, elem * downMin});
                }

                // RIGHT
                if(j+1 < n) {
                    auto [rightMax, rightMin] = dp[i][j+1];
                    maxVal = max({maxVal, elem * rightMax, elem * rightMin});
                    minVal = min({minVal, elem * rightMax, elem * rightMin});
                }

                dp[i][j] = {maxVal, minVal};
            }
        }

        return dp[0][0];
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        auto [maxVal, minVal] = tab(grid);

        if(maxVal < 0) return -1;
        return maxVal % MOD;
    }
};