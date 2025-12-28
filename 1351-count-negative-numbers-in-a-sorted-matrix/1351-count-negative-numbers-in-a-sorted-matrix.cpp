class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for(int i = 0; i < rows; i++) {
            int negIdx = -1;
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] < 0) {
                    negIdx = j;
                    break;
                }
            }
            
            ans += (negIdx == -1) ? 0 : cols - negIdx;
        }
        
        return ans;
    }
};