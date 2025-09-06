#define ll long long
class Solution {
public:
    ll solve(ll l, ll r) {
        // l, R
        // 1 to 3 : 1 steps
        // 4 to 15 : 2 steps
        ll L = 1, S = 1, ans = 0;

        while(L <= r) {
            ll R = (4 * L) - 1;
            ll start = max(L, l);
            ll end = min(R, r);

            if(start <= end) {
                ll no_elems = end - start + 1;
                ans += (no_elems * S);
            }

            S++;
            L *= 4;
        }

        return ans;
    }

    long long minOperations(vector<vector<int>>& queries) {
        ll result = 0;

        for(auto &query : queries) {
            int l = query[0];
            int r = query[1];

            ll steps = solve(l,r);

            result += (steps + 1) / 2;
        }

        return result;
    }
};