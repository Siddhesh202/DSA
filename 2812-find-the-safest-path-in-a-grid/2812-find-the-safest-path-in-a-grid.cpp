#define P pair<int,int>
class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    vector<vector<int>> fillSafeness(vector<vector<int>>& grid) {
        vector<vector<int>> safeness(n,vector<int>(n,0)), visited(n,vector<int>(n,0));
        queue<P> q;

        // put all thieves in queue and start BFS from them
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto &dir : dirs) {
                int newi = node.first + dir[0];
                int newj = node.second + dir[1];

                if(newi >= 0 && newi < n && newj >= 0 && newj < n && !visited[newi][newj]) {
                    q.push({newi, newj});
                    visited[newi][newj] = true;
                    safeness[newi][newj] = safeness[node.first][node.second] + 1;
                }
            }
        }

        return safeness;
    }

    bool check(vector<vector<int>>& safeness, int tar) {
        if (safeness[0][0] < tar) return false;
        
        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<P> q;
        q.push({0,0}); visited[0][0] = true;

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i == n-1 && j == n-1) return true;

            for(auto &dir : dirs) {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi >= 0 && newi < n && newj >= 0 && newj < n && !visited[newi][newj] && safeness[newi][newj] >= tar) {
                    q.push({newi, newj});
                    visited[newi][newj] = true;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        int l = 0, h = 2*n, ans = INT_MIN;

        // base case
        if(n == 1) return 0;

        // Fill safeness
        vector<vector<int>> safeness = fillSafeness(grid);

        // ab binary search lagao
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(check(safeness, mid)) {
                ans = mid;
                l = mid+1;
            }
            else h = mid - 1;
        }

        return ans;
    }
};