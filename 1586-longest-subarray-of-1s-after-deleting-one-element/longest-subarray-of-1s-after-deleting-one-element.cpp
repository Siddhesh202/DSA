class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0; int r = 0;
        int zeroCnt = 0;
        int maxLen = INT_MIN;

        while(r < nums.size()) {
            if(nums[r] == 0)
                zeroCnt++;

            while(zeroCnt > 1) {
                if(nums[l] == 0)
                    zeroCnt--;
                l++;
            }

            maxLen = max(maxLen, r-l);
            r++;
        }

        return maxLen;
    }
};