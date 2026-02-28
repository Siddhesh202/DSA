#define MOD 1000000007
#define ll long long
class Solution {
public:
    string getBinaryString(int n) {
        string ans = "";
        int fIdx = -1;

        for(int i = 0; i < 32; i++) {
            ans += (n & (1 << i)) ? "1" : "0";
        }

        reverse(ans.begin(), ans.end());

        for(int i = 0; i < 32; i++) {
            if(ans[i] == '1') {
                fIdx = i;
                break;
            }
        }

        if(fIdx != -1) return ans.substr(fIdx, 32-fIdx);
        return ans;
    }

    int concatenatedBinary(int n) {
        ll ans = 0;
 
        for(int i = 1; i <= n; i++) {
            int bits = (int)log2(i) + 1;
            ans = ((ans << bits) % MOD + i) % MOD;
        }

        return ans;
    }
};