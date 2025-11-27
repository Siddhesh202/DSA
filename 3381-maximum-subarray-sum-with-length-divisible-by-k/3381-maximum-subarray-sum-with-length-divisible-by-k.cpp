#define ll long long
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll maxSum = LLONG_MIN;
        vector<ll> prefSum(n, 0);

        // 1. calculate prefix sum
        for(int i = 0; i < n; i++) {
            prefSum[i] += (i > 0 ? prefSum[i-1] + nums[i] : nums[i]);
        }

        // 2. Apply Kadane
        for(int start = 0; start < k; start++) {
            int i = start, j = i + k - 1;
            ll currSum = 0;
            while(i < n && j < n) {
                
                ll subSum = prefSum[j] - (i > 0 ? prefSum[i-1] : 0);

                currSum = max(subSum, subSum + currSum);

                maxSum = max(maxSum, currSum);

                i = j + 1;
                j = i + k - 1;
            }
        }

        return maxSum;
    }
};