class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dp[501][501][4][2];

    int solve(vector<vector<int>>& grid, int i, int j, int d, bool canTurn, int val) {
        // base case
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != val) return 0;

        if(dp[i][j][d][canTurn] != -1) return dp[i][j][d][canTurn];

        int nextVal = (val == 2) ? 0 : 2;
        int newi, newj;

        // no turn
        newi = i + dirs[d][0];
        newj = j + dirs[d][1];
        int opt1 = solve(grid, newi, newj, d, canTurn, nextVal);

        // turn
        int newdir = (d+1) % 4; // clockwise turn
        newi = i + dirs[newdir][0];
        newj = j + dirs[newdir][1];
        int opt2 = INT_MIN;
        if(canTurn) opt2 = solve(grid, newi, newj, newdir, !canTurn, nextVal);

        return dp[i][j][d][canTurn] =  max(opt1, opt2) + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    for(int d = 0; d < 4; d++) {
                        bool canTurn = true;
                        int newi = i + dirs[d][0];
                        int newj = j + dirs[d][1];
                        res = max(res, solve(grid, newi, newj, d, canTurn, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};