class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1); // -1 means unreachable state from 0
        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                int diff = nums[j] - nums[i];

                if(dp[j] != -1 && abs(diff) <= target) 
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return dp[n-1] == 0 ? -1 : dp[n-1];
    }
};

// dp
// 1 3 6 4 1 2
// 0 1 0 2 2 3