class Solution {
public:
    int f(vector<int>& nums, int player, int i, int j, vector<vector<vector<int>>>& dp) {
        if(i == j) return nums[i];

        if(dp[i][j][player] != -1) return dp[i][j][player];
        // 2 opts present
        if(player == 0) // player 1
        {
            int opt1 = nums[i] + f(nums, 1, i+1, j, dp);
            int opt2 = nums[j] + f(nums ,1, i, j-1, dp);
            return dp[i][j][player] = max(opt1, opt2);
        }
        else {
            int opt1 = f(nums, 0, i+1, j, dp);
            int opt2 = f(nums, 0, i, j-1, dp);
            return dp[i][j][player] = min(opt1, opt2);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(2, -1)));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int player1_max_score = f(nums, 0, 0, n-1, dp);

        if(2 * player1_max_score >= sum)
            return true;
        
        return false;
    }
};