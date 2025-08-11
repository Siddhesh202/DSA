#define ll long long
#define MOD 1000000007

class Solution {
public:
    ll modPow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    ll modInverse(ll x) {
        return modPow(x, MOD - 2);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> powers;
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & n) powers.push_back(1LL << i);
        }

        vector<ll> prefsum(powers.size());
        prefsum[0] = powers[0] % MOD;
        for (int i = 1; i < powers.size(); i++)
            prefsum[i] = (prefsum[i - 1] * powers[i]) % MOD;

        vector<int> ans;
        for (auto &query : queries) {
            int left = query[0], right = query[1];
            ll prod = prefsum[right];
            if (left > 0) {
                prod = (prod * modInverse(prefsum[left - 1])) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
