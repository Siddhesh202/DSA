class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int i = 0, j = 2, n = nums.size();

        for(int i = 0, j = 2; j < n; i++, j++) {
            if(2 * (nums[i] + nums[j]) == nums[i+1]) ans++;
        }

        return ans;
    }
};