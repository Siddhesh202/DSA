class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);
        vector<int> ans;
        int maxl = 1, maxi = 0;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = 1 + dp[j];
                    prev_idx[i] = j;
                    if(dp[i] >= maxl) {
                        maxl = dp[i];
                        maxi = i;
                    }
                }
            }
        }

        while(maxi >= 0) {
            ans.push_back(nums[maxi]);
            maxi = prev_idx[maxi];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};