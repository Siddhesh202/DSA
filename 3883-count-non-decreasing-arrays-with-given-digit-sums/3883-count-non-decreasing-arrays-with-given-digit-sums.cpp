#define MOD 1000000007
#define ll long long

class Solution {
public:
    int n;
    vector<vector<int>> valid;

    int Sum(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countArrays(vector<int>& digitSum) {
        n = digitSum.size();

        valid.resize(51);
        for(int i = 0; i <= 5000; i++) {
            valid[Sum(i)].push_back(i);
        }

        // dp for last index
        vector<ll> dp(valid[digitSum[n-1]].size(), 1);

        // process from back
        for(int idx = n - 2; idx >= 0; idx--) {
            auto &cur = valid[digitSum[idx]];
            auto &next = valid[digitSum[idx+1]];

            vector<ll> new_dp(cur.size(), 0);

            // suffix sum on next dp
            int m = next.size();
            vector<ll> suffix(m + 1, 0);
            for(int i = m - 1; i >= 0; i--) {
                suffix[i] = (suffix[i+1] + dp[i]) % MOD;
            }

            // two pointer to find first >=
            int j = 0;
            for(int i = 0; i < cur.size(); i++) {
                while(j < m && next[j] < cur[i]) j++;
                if(j < m) {
                    new_dp[i] = suffix[j];
                }
            }

            dp = new_dp;
        }

        ll ans = 0;
        for(ll x : dp) ans = (ans + x) % MOD;

        return ans;
    }
};