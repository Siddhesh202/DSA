#define ll long long
class Solution {
public:
    int n;
    vector<vector<ll>> dp;
    ll solve(vector<ll> &cost, int end, int idx, int k) {
        if(k == 0) return 0;

        if(idx > end) return LLONG_MAX;

        if(dp[idx][k] != -1) return dp[idx][k];

        // take
        ll next = solve(cost, end, idx+2, k-1);
        ll take = (next == LLONG_MAX ? LLONG_MAX : cost[idx] + next);

        // skip if possible
        ll notake = solve(cost, end, idx+1, k);

        return dp[idx][k] = min(take, notake);
    }

    int minOperations(vector<int>& nums, int k) {
        n = nums.size();
        vector<ll> cost;

        for(int i = 0; i < n; i++) {
            cost.push_back(max(0, max(nums[(i-1+n)%n], nums[(i+1)%n]) + 1 - nums[i]));
        }

        dp.assign(n, vector<ll>(k+1, -1));
        ll opt1 = solve(cost, n-2, 0, k); // 0 to n-2

        dp.clear();
        dp.assign(n, vector<ll>(k+1, -1));
        ll opt2 = solve(cost, n-1, 1, k); // 1 to n-1

        ll ans = min(opt1, opt2);

        return (ans == LLONG_MAX) ? -1 : ans;
    }
};