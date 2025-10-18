class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, prevMax = INT_MIN;

        for(auto &num : nums) {
            int lower_bound = num - k;
            int upper_bound = num + k;

            if(prevMax < lower_bound) {
                prevMax = lower_bound;
                ans++;
            }
            else if(prevMax < upper_bound) {
                prevMax += 1;
                ans++;
            }
        }

        return ans;
    }
};