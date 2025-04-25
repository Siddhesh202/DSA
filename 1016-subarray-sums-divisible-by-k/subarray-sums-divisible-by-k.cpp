#define ll long long
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        mp[0] = 1;
        ll sum = 0, ans = 0;

        for(int i = 0; i < n; i++) {
           sum += nums[i];
           ll r = sum % k;
           
           if(r < 0) r += k;

           if(mp.count(r)) ans += mp[r];

           mp[r]++;
        }

        return ans;
    }
};