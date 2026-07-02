#define P pair<int,int>
class Solution {
public:
    int m,n;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size(), n = grid[0].size();
        if(grid[0][0] >= health) return false;

        priority_queue<vector<int>> pq;
        vector<vector<int>> ans(m, vector<int>(n, INT_MIN));
        ans[0][0] = health - grid[0][0];
        pq.push({ans[0][0], 0, 0});

        while(!pq.empty()) {
            int currHealth = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];

            pq.pop();

            for(auto &dir : dirs) {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi >= 0 && newi < m && newj >= 0 && newj < n && currHealth - grid[newi][newj] > ans[newi][newj]) {
                    pq.push({currHealth - grid[newi][newj], newi, newj});
                    ans[newi][newj] = currHealth - grid[newi][newj];
                }
            }
        }

        if(ans[m-1][n-1] > 0) return true;
        else return false;
    }
};