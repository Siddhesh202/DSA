class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, minEl = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - minEl;
            ans = max(ans, diff);
            minEl = min(minEl, nums[i]);
        }

        return ans == 0 ? -1 : ans;
    }
};