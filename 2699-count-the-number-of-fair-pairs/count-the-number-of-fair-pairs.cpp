#define ll long long
#include <algorithm>
class Solution {
public:
    ll countLess(vector<int>& nums, int val) {
        int n = nums.size();
        ll ans = 0;
        for(int i = 0; i < n-1; i++) {
            auto it = upper_bound(nums.begin()+i+1, nums.end(), val - nums[i]);
            ans += (it - nums.begin()) - i - 1;
        }

        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countLess(nums, upper) - countLess(nums, lower-1);
    }
};