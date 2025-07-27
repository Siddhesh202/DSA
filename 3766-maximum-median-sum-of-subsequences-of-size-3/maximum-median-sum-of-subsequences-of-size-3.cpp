#define ll long long
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        ll ans = 0;
        sort(nums.begin(), nums.end());

        while(i < j) {
            int a = nums[i];
            int b = nums[j-1];
            int c = nums[j];

            ans += b;
            j-=2;
            i++;
        }

        return ans;
    }
};