#define MOD 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26, 0);

        for(auto &ch : s) mp[ch-'a']++;

        for(int cnt = 1; cnt <= t; cnt++) {
            vector<int> temp(26, 0);
            for(int i = 0; i < 26; i++) {
                char ch = i + 'a';
                if(mp[i] > 0) {
                    if(ch != 'z') {
                        char newch = ch+1;
                        temp[newch-'a'] = (temp[newch-'a'] + mp[i]) % MOD;
                    }
                    else {
                        temp[0] = (temp[0] + mp[i]) % MOD;
                        temp[1] = (temp[1] + mp[i]) % MOD;
                    }
                }
            }
            mp = temp;
        }

        int ans = 0;
        for(auto &val : mp) ans = (ans + val) % MOD;

        return ans;
    }
};