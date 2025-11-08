#define ll long long
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;

        int res = 0, sign = 1;
        vector<ll> F(32); // F(i) = 2*F(i-1) + 1;
        F[0] = 1;

        // Fill up the F arr
        for(int i = 1; i < 32; i++) {
            F[i] = (2 * F[i-1]) + 1;
        } 

        for(int i = 31; i >= 0; i--) { // left to rigt solving
            if((1 << i) & n) { // ith bit set hai
                res += sign * F[i];
                sign *= -1;
            }
        }

        return res;
    }
};