#define MOD 1000000007
#define ll long long
class Solution {
public:
    ll fact(ll n) {
        if(n <= 1) return 1;
        return (n * fact(n-1)) % MOD;
    }

    ll power(ll a, ll b) {
        if(b == 0) return 1;

        ll half = power(a, b/2) % MOD;
        ll ans = (half * half) % MOD;

        if(b%2 != 0) ans = (ans * a) % MOD;

        return ans;
    }

    ll nCr(int n, int r) {
        ll a = fact(n) % MOD;
        ll b = (fact(r) * fact(n-r)) % MOD;

        return a * power(b, MOD-2) % MOD; 
    }

    int countVisiblePeople(int n, int pos, int k) {
        ll ans = (nCr(n-1, k) * 2) % MOD;
        return ans;
    }
};

// 0 1 2 3 4 5 6 7 8 9 ........ n-1

// 0 1 2 , pos = 2, k = 1
// L R L
// L R R
// R L L
// R L R


// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15     pos = 7, k = 5
// Left mai 0 people
// Left mai 1 people
// Left mai 2 people
// .
// .
// Left mai 5 people

// Let's say I want x people to left and (k-x) people to right
// len to left = (pos - 0) = pos
// pos ---> Select x people from pos 
// n-pos-1 ---> Select (k-x) people from pos
// Hence no of ways is (pos C x) * (n-pos-1 C k-x) * 2