#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minkPos = -1, maxkPos = -1;
        int culIdx = -1;
        int n = nums.size();
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == minK) minkPos = i;
            if(nums[i] == maxK) maxkPos = i;
            if(nums[i] < minK || nums[i] > maxK) culIdx = i; 

            // count of valid fixed bound subarrs ending at i
            int pos = min(minkPos, maxkPos);
            ll temp = pos - culIdx;
            ans += (temp <= 0) ? 0 : temp;
        }

        return ans;

    }
};