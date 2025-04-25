#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int,ll> mp; // remainder, count
        ll sum = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) nums[i] = 1;
            else nums[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ll r1 = sum % modulo;
            ll r2 = (r1 - k + modulo) % modulo;

            if(mp.count(r2))
                ans += mp[r2];
            
            mp[r1]++;
        }

        return ans;

    }
};