class Solution {
public:
    int n;

    int helper(vector<int>& piles, vector<int>& suffixSum, int idx, int M, vector<vector<int>>& dp) {
        if(idx >= n) return 0;

        if(dp[idx][M] != -1) return dp[idx][M];
        int result = 0;
        for(int x = 1; x <= min(2*M, n-idx); x++) {
            result = max(result, suffixSum[idx] - helper(piles, suffixSum, idx+x, max(M,x), dp));
        }
        return dp[idx][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        if(n == 1) return piles[0];
        vector<int> suffixSum(n);
        vector<vector<int>> dp(n, vector<int>(n,-1));
        suffixSum[n-1] = piles[n-1];

        for(int i = n-2; i >= 0; i--) suffixSum[i] = suffixSum[i+1] + piles[i];

        return helper(piles, suffixSum, 0, 1, dp);
    }
};