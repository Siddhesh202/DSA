class Solution {
public:
    void markGuarded(int row, int col, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // UP
        for(int i = row-1; i >= 0; i--) {
            if(grid[i][col] == 2 || grid[i][col] == 3)
                break;
            grid[i][col] = 1;
        }

        // DOWN
        for(int i = row+1; i < m; i++) {
            if(grid[i][col] == 2 || grid[i][col] == 3)
                break;
            grid[i][col] = 1;
        }

        // LEFT
        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 2 || grid[row][j] == 3)
                break;
            grid[row][j] = 1;
        }

        // RIGHT
        for(int j = col+1; j < n; j++) {
            if(grid[row][j] == 2 || grid[row][j] == 3)
                break;
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // mark guards
        for(auto& guard : guards)
            grid[guard[0]][guard[1]] = 2;
        
        // mark walls
        for(auto& wall : walls)
            grid[wall[0]][wall[1]] = 3;
        
        for(auto& guard : guards)
        {
            int i = guard[0];
            int j = guard[1];
            markGuarded(i, j, grid);
        }

        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};