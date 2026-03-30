class Solution {
public:
    int m,n;

    int bfs(vector<vector<int>>& grid) {
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        queue<tuple<int,int,int>> q;
        
        q.push({0,0,grid[0][0]});
        vis[0][0][grid[0][0]] = true;

        while(!q.empty()) {
            auto [i, j, curr_xor] = q.front();
            q.pop();

            // go right
            if(j+1 < n) {
                int new_xor = curr_xor ^ grid[i][j+1];
                if(!vis[i][j+1][new_xor]) {
                    q.push({i, j+1, new_xor});
                    vis[i][j+1][new_xor] = true;
                }
            }

            // go down
            if(i+1 < m) {
                int new_xor = curr_xor ^ grid[i+1][j];
                if(!vis[i+1][j][new_xor]) {
                    q.push({i+1, j, new_xor});
                    vis[i+1][j][new_xor] = true;
                }
            }
        }

        for(int i = 0; i < 1024; i++) if(vis[m-1][n-1][i]) return i; 
        
        return 0;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        return bfs(grid);
    }
};