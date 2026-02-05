class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            int idx = ((i+nums[i]) % n + n) % n;
            // int idx = ((i + nums[i]) % n + n) % n;
            result.push_back(nums[idx]);

        }

        return result;
    }
};