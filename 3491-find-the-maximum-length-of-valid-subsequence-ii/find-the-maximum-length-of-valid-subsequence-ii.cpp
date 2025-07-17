class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                int mod = (nums[i] + nums[j]) % k;

                dp[i][mod] = max(dp[i][mod], 1 + dp[j][mod]);

                ans = max(ans, dp[i][mod]);
            }
        }

        return ans;
    }
};

// 1, 4, 2, 3, 1, 4
// [0,0,0], [0,0,1], [1,0,0], [0,1,1], [2,2,2], []