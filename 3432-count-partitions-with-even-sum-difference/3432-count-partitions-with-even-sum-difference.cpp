class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0, cumSum = 0, n = nums.size();

        for(int i = 0; i < n-1; i++) {
            cumSum += nums[i];
            int lSum = cumSum;
            int rSum = totalSum - cumSum;

            ans += (abs(rSum - lSum) % 2 == 0);
        }

        return ans;
    }
};