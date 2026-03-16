class Solution {
public:
    int m, n;

    int dfsLeftDiag(vector<vector<int>>& grid, int i, int j, int side) {
        if(side == 0) return grid[i][j];
        return grid[i][j] + dfsLeftDiag(grid, i+1, j-1, side-1);
    }

    int dfsRightDiag(vector<vector<int>>& grid, int i, int j, int side) {
        if(side == 0) return grid[i][j];
        return grid[i][j] + dfsRightDiag(grid, i+1, j+1, side-1);
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        set<int> uniqueSum;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                // Let the boundary checks handle the maximum valid side length naturally
                for(int side = 0; side <= min(m, n); side++) { 
                 
                    int x1 = row - side, y1 = col;
                    int x2 = row, y2 = col - side;
                    int x3 = row + side, y3 = col;
                    int x4 = row, y4 = col + side;

                    // If the rhombus fits within the grid
                    if(x1 >= 0 && x1 < m && x2 >= 0 && x2 < m && x3 >= 0 && x3 < m && x4 >= 0 && x4 < m
                    && y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && y3 >= 0 && y3 < n && y4 >= 0 && y4 < n) {
                        
                        if (side == 0) {
                            uniqueSum.insert(grid[row][col]);
                        } else {
                            int localSum = 0;
                            localSum += dfsLeftDiag(grid, x1, y1, side);
                            localSum += dfsRightDiag(grid, x1, y1, side);
                            localSum += dfsRightDiag(grid, x2, y2, side);
                            localSum += dfsLeftDiag(grid, x4, y4, side);
                            
                            // Remove the double-counted corners
                            localSum -= grid[x1][y1];
                            localSum -= grid[x2][y2];
                            localSum -= grid[x3][y3];
                            localSum -= grid[x4][y4];

                            uniqueSum.insert(localSum);
                        }
                    }
                }
            }
        }

        // Only grab up to 3 elements, don't pad with zeros
        vector<int> ans;
        auto it = uniqueSum.rbegin();
        for (int i = 0; i < 3 && it != uniqueSum.rend(); i++, it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};