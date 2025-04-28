#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        ll ans = 0, sum = 0;
        int i = 0, j = 0;

        while(j < n) {
            sum += nums[j];

            while(i <= j && (j - i + 1) * sum >= k) {
                sum -= nums[i];
                i++;
            }

            if(sum < k) ans += (j - i + 1);
            j++;
        }

        return ans;

    }
};