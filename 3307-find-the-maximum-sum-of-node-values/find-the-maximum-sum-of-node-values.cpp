#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int cnt = 0, mini = INT_MAX;
        ll ans = 0;

        for(int i = 0; i < nums.size(); i++){
            int newnum = nums[i] ^ k;

            if(newnum > nums[i]) {
                cnt++;
                ans += newnum;
            }
            else {
                ans += nums[i];
            }

            mini = min(mini, abs(nums[i] - newnum));
        }

        if(cnt % 2 != 0) {
            ans -= mini;
        }

        return ans;
    }
};