#define ll long long
class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void dfs(int i, int j, ll &sum, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        sum += grid[i][j];

        for(auto &dir : dirs) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if(newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] != 0 && !visited[newi][newj])
                dfs(newi, newj, sum, grid, visited);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != 0 && !visited[i][j]) {
                    ll sum = 0;
                    dfs(i, j, sum, grid, visited);
                    if(sum % k == 0) ans++;
                }
            }
        }

        return ans;
    }
};