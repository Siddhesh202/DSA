class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n, 0);
        
        int currMaxi = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            if(currMaxi < nums[i]) {
                currMaxi = nums[i];
            }

            arr[i] = currMaxi;
        }

        int ans = -1;
        for(int i = 0; i < n-k; i++) {
            ans = max(ans, nums[i] + arr[i+k]);
        }

        return ans;
    }
};