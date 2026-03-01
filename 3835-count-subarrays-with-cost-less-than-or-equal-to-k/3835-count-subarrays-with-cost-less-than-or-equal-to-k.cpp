#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0, low = 0, n = nums.size();
        multiset<int> st;

        for(int high = 0; high < n; high++) {
            st.insert(nums[high]);

            while(!st.empty()) {
                ll mn = *st.begin();
                ll mx = *st.rbegin();
                ll len = high - low + 1;
                ll cost = (mx - mn) * len;

                if(cost <= k) break;

                st.erase(st.find(nums[low]));
                low++;
            }

            ans += (high - low + 1);
        }

        return ans;
    }
};