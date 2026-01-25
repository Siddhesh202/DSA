class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int i = 0, n = nums.size();

        sort(nums.begin(), nums.end());

        while(i+k-1 < n) {
            int j = i + k - 1;

            int diff = nums[j] - nums[i];
            ans = min(ans, diff);
            i++;
        }

        return ans;
    }
};

// 1, 4, 7, 9
// k = 2, i = 0, j = i+k-1 = 0+2-1 = 1