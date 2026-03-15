#define M 1000000007
#define ll long long
class Fancy {
public:
    vector<ll> seq;
    ll add, mult;

    Fancy() {
        add = 0;
        mult = 1;
    }
    
    void append(int val) {
        ll a = (val - add + M) % M;
        ll b = power(mult, M-2);
        seq.push_back((a * b) % M);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        add = (add * m) % M;
        mult = (mult * m) % M;
    }
    
    int getIndex(int idx) { 
        if(idx >= seq.size()) return -1;

        int x = seq[idx];
        return ((x * mult) + add) % M;
    }

    ll power(ll a, ll b) {
        if(b == 0) return 1;

        ll half = power(a, b/2);

        ll ans = (half * half) % M;

        if(b%2 != 0) ans *= a;

        return ans % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */