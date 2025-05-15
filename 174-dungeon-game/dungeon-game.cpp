class Solution {
public:
    int m, n;
    int dp[201][201];
    int solve(vector<vector<int>>& dungeon, int i, int j) {
        if(i >= m || j >= n) return INT_MAX;

        if(i == m-1 && j == n-1) {
            return dungeon[i][j] <= 0 ? abs(dungeon[i][j]) + 1 : 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // go right
        int right = solve(dungeon, i, j+1);

        // go down
        int down = solve(dungeon, i+1, j);

        if(dungeon[i][j] <= 0) {
            return dp[i][j] = abs(dungeon[i][j]) + min(down, right);
        }

        return dp[i][j] = min(down, right) - dungeon[i][j] > 0 ? min(down, right) - dungeon[i][j] : 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(dungeon, 0, 0);
        return ans;
    }
};