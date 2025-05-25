#define ll long long
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n <= k && m <= k) return 0;
        else if(n > k) {
            ll ans = (ll)k * (n-k);
            return ans;
        }
        else {  // m > k
            ll ans = (ll)k * (m-k);
            return ans;
        }

    }
};

// eg n > k (eg n = 5, k = 3)
// 3 and 5-3 = 2
// k and n-k