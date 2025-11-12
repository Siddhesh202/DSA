class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cntOne = 0;

        for(auto &num : nums) if(num == 1) cntOne++;

        if(cntOne > 0) return n - cntOne;

        // If no cnt one is found
        int oprs = INT_MAX;
        for(int i = 0; i < n-1; i++) {
            int GCD = nums[i];
            for(int j = i+1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);

                if(GCD == 1) {
                    oprs = min(j-i, oprs);
                    break;
                }
            }
        }

        if(oprs == INT_MAX) return -1;

        return oprs + (n-1);
    }
};