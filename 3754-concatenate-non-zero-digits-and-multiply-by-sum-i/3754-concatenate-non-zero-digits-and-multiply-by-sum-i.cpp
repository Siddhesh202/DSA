#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;

        string num = to_string(n);
        ll ans = 0, sum = 0;
        
        for(int i = 0; i < num.size(); i++) {
            int dig = num[i] - '0';

            if(dig != 0) ans = (ans * 10) + dig;
            sum += dig;
        }

        return ans * sum;
    }
};