class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        vector<int> ans;
        dp[0] = 1;

        if(n==1){
            ans.push_back(nums[0]);   
            return ans;
        }
        // hash[0] = nums[0];
        int omax = 0;
        int lastIndex;
        for(int i = 1; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0 && dp[i] < 1+dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if(omax < dp[i]) {
                omax = dp[i];
                lastIndex = i;
            }
        }
        
        while(hash[lastIndex] != lastIndex) {
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }

        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }

};