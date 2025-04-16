#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0;
        ll pairs = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        while(j < n) {
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while(pairs >= k & i <= j) {
                ans += (n-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return ans;
    }
};