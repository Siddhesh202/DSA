#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll ans = INT_MIN;

        for(int i = 0; i < n-2; i++) {
            for(int j = i + 1; j < n-1; j++) {
                for(int k = j + 1; k < n; k++) {
                    ans = max(ans, (ll) (nums[i]- nums[j]) * nums[k]);
                }
            }
        }

        return ans < 0 ? 0 : ans;
    }
};