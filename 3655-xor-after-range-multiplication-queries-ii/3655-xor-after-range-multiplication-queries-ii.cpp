#define MOD 1000000007
#define ll long long
class Solution {
public:
    int n;
    ll pow(int a, int b) {
        if(b == 0) return 1;

        ll half = pow(a, b/2);
        ll ans = (half * half) % MOD;

        if(b % 2 != 0) ans = (ans * a) % MOD;
        return ans;
    }

    ll fermatTheorem(int a, int b) { // need to do (a / b) % MOD --> a * (b ^ M-2) % MOD 
        ll x = a;
        ll y = pow(b, MOD-2) % MOD;
        return (x * y) % MOD;
    }

    void DAT(vector<int> &nums, int k, vector<vector<int>>& queries) {
        vector<ll> diff(n, 1);

        // populate diff arr
        for(auto &query : queries) {
            int l = query[0], r = query[1], v = query[2];

            diff[l] = (diff[l] * v) % MOD;
            int steps = (r - l) / k;
            int next = l + (steps + 1) * k;

            if(next < n) diff[next] = fermatTheorem(diff[next], v); // do (diff[next] / val) % MOD
        }

        //Cumulative product
        for(int i = 0; i < n; i++) {
            if(i-k >= 0)
                diff[i] = (diff[i] * diff[i-k]) % MOD;
        }

        //Apply diff to nums
        for(int i = 0; i < n; i++) {
            nums[i] = (1LL * nums[i] * diff[i]) % MOD;
        }
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        int blockSize = ceil(sqrt(n)), ans = 0;
        unordered_map<int,vector<vector<int>>> smallKMap;

        for(auto &query : queries) {
            int l = query[0], r = query[1], k = query[2], v = query[3];

            if(k >= blockSize) { // if k is large do square root decomposition
                for(int i = l; i <= r; i +=k) nums[i] = (1LL * nums[i] * v) % MOD;
            }
            else { // Apply Difference Array Technique with Jumps for smaller k
                smallKMap[k].push_back({l, r, v});
            }
        }

        // process elements in small k using differnce array technique
        for(auto &[k, smallQueries] : smallKMap) {
            DAT(nums, k, smallQueries);
        } 

        // finally do the XOR of all elements
        for(int i = 0; i < n; i++) ans ^= nums[i];

        return ans;
    }
};