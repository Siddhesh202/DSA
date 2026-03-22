class Solution {
public:
    int n;
    int dp[40][16384];
    int solve(vector<int>& nums, int idx, int currXor, int target) {
        if(idx >= n) {
            if(currXor == target) return 0;
            return INT_MIN;
        }

        if(dp[idx][currXor] != -1) return dp[idx][currXor];

        // take
        int take = 1 + solve(nums, idx+1, currXor ^ nums[idx], target);

        // no take
        int notake = solve(nums, idx+1, currXor, target);

        return dp[idx][currXor] = max(take, notake);
    }

    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int maxKeep = solve(nums, 0, 0, target);

        if(maxKeep < 0) return -1;
        return n - maxKeep;
    }
};