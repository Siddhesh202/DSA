class Solution {
public:
    int m,n;
    vector<int> costs = {0, 1, 1};

    int solve(vector<vector<int>>& grid, int k, int i, int j, vector<vector<vector<int>>> &dp) {
        int cost = costs[grid[i][j]];
        if(k < 0) return INT_MIN;

        if(i == m-1 && j == n-1) {
            if(cost <= k) return grid[i][j];
            return INT_MIN;
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        // go right
        int right = INT_MIN;
        if(j+1 < n) right = solve(grid, k-cost, i, j+1, dp);

        // go down
        int down = INT_MIN;
        if(i+1 < m) down = solve(grid, k-cost, i+1, j, dp);

        int best = max(right, down);
        if(best == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] =  best + grid[i][j];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = solve(grid, k, 0, 0, dp);
        if(ans == INT_MIN) return -1;
        return ans;
    }
};