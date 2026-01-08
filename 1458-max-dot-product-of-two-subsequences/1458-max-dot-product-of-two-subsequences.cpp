class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 || j < 0)
            return -1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        int opt1 = nums1[i] * nums2[j] + f(nums1, nums2, i-1, j-1, dp);
        int opt2 = f(nums1, nums2, i-1, j, dp);
        int opt3 = f(nums1, nums2, i, j-1, dp);
        int opt4 = nums1[i]*nums2[j];

        return dp[i][j] = max(max(opt1, opt2), max(opt3, opt4));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1e9));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int opt1 = nums1[i-1] * nums2[j-1] + dp[i-1][j-1];
                int opt2 = dp[i-1][j];
                int opt3 = dp[i][j-1];
                int opt4 = nums1[i-1]*nums2[j-1];
                dp[i][j] = max(max(opt1, opt2), max(opt3, opt4));
            }
        }
        return dp[n][m];
    }
};