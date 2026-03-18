class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> prev(n, 0);

        for(int row = 0; row < m; row++) {
            int currSum = 0;
            for(int col = 0; col < n; col++) {
                currSum += grid[row][col];
                prev[col] = currSum + prev[col];
                if(prev[col] <= k) ans++;
            }
        }

        return ans;
    }
};