#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0, cnt = 0;

        for(auto &num : nums) {
            if(num == 0) {
                cnt++;
                ans += cnt;
            }
            else
                cnt = 0;
        }

        return ans;
    }
};