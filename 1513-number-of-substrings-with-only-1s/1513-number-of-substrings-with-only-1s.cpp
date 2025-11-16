#define MOD 1000000007
#define ll long long
class Solution {
public:
    int numSub(string s) {
        ll res = 0, continuousOne = 0;

        for(auto &ch : s) {

            if(ch == '1') {
                continuousOne++;
                res = (res + continuousOne) % MOD;
            }
            else {
                continuousOne = 0;
            }
        }

        return res;
    }
};