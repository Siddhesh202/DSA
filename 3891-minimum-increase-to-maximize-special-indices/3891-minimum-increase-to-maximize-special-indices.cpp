#define ll long long
#define P pair<int,ll>
class Solution {
public:
    int n;
    vector<vector<ll>> dp;
    ll solve(vector<ll> &cost, int idx, int canSkip) {
        if(idx >= cost.size()) return 0;

        if(dp[idx][canSkip] != -1) return dp[idx][canSkip];

        // take
        ll next = solve(cost, idx+2, canSkip);
        ll take = (next == LLONG_MAX ? LLONG_MAX : cost[idx] + next);

        // skip if possible
        ll notake = LLONG_MAX;
        if(canSkip) notake = solve(cost, idx+1, 0);

        return dp[idx][canSkip] = min(take, notake);
    }
    
    long long minIncrease(vector<int>& nums) {
        n = nums.size();
        vector<ll> cost;

        for(int i = 1; i < n-1; i++) {
            cost.push_back(max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]));
        }

        // Case 1: peaks at odd indices
        ll oddCost = 0;
        for (int i = 0; i < cost.size(); i += 2) {
            oddCost += cost[i];
        }
        
        // If n is odd → only one pattern possible
        if (n % 2 == 1) {
            return oddCost;
        }

        // For even --> we can skip at most 1 times
        dp.assign(cost.size(), vector<ll>(2, -1));
        return solve(cost, 0, 1);
    }
};

// [1,2,3,4,5,6,7,8]

// Now the problem becomes
// minimize the cost
// no two adj indices should be selected
// select maximum indices