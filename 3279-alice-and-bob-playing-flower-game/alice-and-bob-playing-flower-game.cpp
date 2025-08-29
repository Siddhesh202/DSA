#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll ans = 0;
        ll e1, o1, e2, o2;

        e1 = floor(n*1.0/2);
        e2 = floor(m*1.0/2);
        o1 = ceil(n*1.0/2);
        o2 = ceil(m*1.0/2);

        return (e1*o2) + (e2*o1);
    }
};