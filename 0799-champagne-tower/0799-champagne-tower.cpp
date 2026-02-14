class Solution {
public:
    double f(int& poured, int i, int j, vector<vector<double>>& dp) {
        if(i < 0 || j < 0 || i < j)
            return 0.0;
        if(i == 0 && j == 0)
            return poured;
        
        if(dp[i][j] != -1.0) return dp[i][j];
        double upperLeft = (f(poured, i-1, j-1, dp) - 1) / 2.0;
        double upperRight = (f(poured, i-1, j, dp) - 1) / 2.0;

        if(upperLeft < 0.0) upperLeft = 0.0;
        if(upperRight < 0.0) upperRight = 0.0;

        return dp[i][j] = upperLeft + upperRight;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1, vector<double>(query_glass+1, -1.0));
        double ans = min(1.0, f(poured, query_row, query_glass, dp));
        return ans;
    }
};