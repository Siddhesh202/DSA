#define ll long long
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        for(int t = 1; t <= 36; t++){
            ll val = (ll)num1 - (1LL * t * num2);

            if(val < 0) return -1;

            int min_bits = __builtin_popcountll(val);

            if(min_bits <= t && t <= val)
                return t; 
        }

        return -1;
    }
};