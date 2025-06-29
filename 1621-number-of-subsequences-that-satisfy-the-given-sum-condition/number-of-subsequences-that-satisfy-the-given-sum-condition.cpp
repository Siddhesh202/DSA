#define ll long long
const ll MOD = 1000000007;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        ll ans = 0;
        vector<ll> power(n, 1);
        sort(nums.begin(), nums.end());

        // Precompute power
        for(int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % MOD;
        }

        // use 2 pointers
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans = (ans % MOD + power[r-l]) % MOD;
                l++;
            }
            else {
                r--;
            }
        }

        return ans;
    }
};