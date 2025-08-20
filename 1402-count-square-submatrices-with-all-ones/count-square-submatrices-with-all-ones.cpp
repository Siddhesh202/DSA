class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= m || j >= n)
            return 0;
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        if(matrix[i][j] == 0)
            return dp[i][j] = 0;
        
        int right = solve(matrix, i, j+1, dp);
        int diag = solve(matrix, i+1, j+1, dp);
        int down = solve(matrix, i+1, j, dp);

        return dp[i][j] = 1 + min(right, min(diag, down));
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i < m; i++) dp[i][0] = matrix[i][0];
        for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 1)
                    dp[i][j] = 1 + min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] });
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                ans += dp[i][j];
        }
        return ans;
    }
};