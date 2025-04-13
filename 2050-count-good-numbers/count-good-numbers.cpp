#define ll long long
class Solution {
ll MOD = 1e9+7;
public:
    ll power(ll x, ll b) {
        if(b == 0) return 1;

        ll half = power(x, b/2) % MOD;
        ll res = (half * half) % MOD;

        if(b%2 == 1)
            res = (res * x) % MOD;
        
        return res;
    }

    int countGoodNumbers(long long n) {
        ll no_even_places = (n+1) / 2;
        ll no_odd_places = n - no_even_places;

        ll a = power(5, no_even_places) % MOD;
        ll b = power(4, no_odd_places) % MOD;

        return (a * b) % MOD;
    }
};