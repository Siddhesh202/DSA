class Solution {
public:
    int n;
    int tab(vector<int>& nums, int target) {
        vector<int> prev(16384, INT_MIN);
        vector<int> curr(16384, INT_MIN);

        // base case
        prev[target] = 0;

        for(int idx = n-1; idx >= 0; idx--) {
            for(int currXor = 0; currXor < 16384; currXor++) {

                int take = 1 + prev[currXor ^ nums[idx]];
                int notake = prev[currXor];

                curr[currXor] = max(take, notake);
            }

            prev = curr;
        }

        return prev[0];
    }

    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        // memset(dp, -1, sizeof(dp));
        int maxKeep = tab(nums, target);

        if(maxKeep < 0) return -1;
        return n - maxKeep;
    }
};