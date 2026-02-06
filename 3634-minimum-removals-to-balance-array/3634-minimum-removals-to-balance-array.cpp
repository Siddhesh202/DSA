#define ll long long
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            ll minEl = nums[i];
            ll maxToGo = minEl * k;

            int pos = upper_bound(nums.begin(), nums.end(), maxToGo) - nums.begin();
            ans = min(ans, (n-pos)+i);
        }
        return ans;
    }
};

// [1, 2, 6, 9]
//  0, 1, 2, 3