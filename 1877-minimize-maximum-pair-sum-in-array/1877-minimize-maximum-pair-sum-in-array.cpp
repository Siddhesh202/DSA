class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;

        for(int i = n/2; i < n; i++) {
            ans = max(ans, nums[i] + nums[n-i-1]);
        }

        return ans;
    }
};