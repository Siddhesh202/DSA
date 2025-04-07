class Solution {
public:
    bool solve(vector<int> &nums, int i, int tar, vector<vector<int>> &dp) {
        if(tar == 0) return true;

        if(tar < 0 || i >= nums.size()) return false;

        if(dp[i][tar] != -1) return dp[i][tar];

        // take 
        bool take = solve(nums, i+1, tar-nums[i], dp);

        // notake
        bool notake = solve(nums, i+1, tar, dp);

        return dp[i][tar] = take || notake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        if(sum % 2 != 0)
            return false;
        
        return solve(nums, 0, sum/2, dp);
    }
};