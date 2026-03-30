class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid, int i, int j, int curr_xor, vector<vector<vector<bool>>> &vis) {
        vis[i][j][curr_xor] = true;

        if(i == m-1 && j == n-1) return;

        // If possible go right
        if(j+1 < n) {
            int nx = curr_xor ^ grid[i][j+1];
            if(!vis[i][j+1][nx]) dfs(grid, i, j+1, nx, vis);
        }

        // If possible go down
        if(i+1 < m) {
            int nx = curr_xor ^ grid[i+1][j];
            if(!vis[i+1][j][nx]) dfs(grid, i+1, j, nx, vis);
        }

        return;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        dfs(grid, 0, 0, grid[0][0], vis);

        for(int i = 0; i < 1024; i++) if(vis[m-1][n-1][i]) return i;

        return 0;
    }
};