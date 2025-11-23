class Solution {
public:
    int n;
    int solve(int idx, int currRem, vector<int>& nums) {
        if(idx >= n)
            return (currRem == 0) ? 0 : INT_MIN;

        // Take
        int opt1 = nums[idx] + solve(idx+1, (currRem + nums[idx]) % 3, nums);

        // No Take
        int opt2 = solve(idx+1, currRem, nums);

        return max(opt1, opt2);
    }

    int tab(vector<int>& nums) {
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        dp[n][1] = dp[n][2] = INT_MIN;

        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < 3; j++) {
                
                // take
                int opt1 = nums[i] + dp[i+1][(j + nums[i]) % 3];

                // no take
                int opt2 = dp[i+1][j];

                dp[i][j] = max(opt1, opt2);
            }
        }

        return dp[0][0];
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        return tab(nums);
    }
};