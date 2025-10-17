#define ll long long
class Solution {
public:
    unordered_map<ll, int> dp;
    int solve(string &s, int &k, ll idx, ll uniqueChars, bool canChange) {
        // base case
        if(idx >= s.length()) return 0;

        ll key = (idx << 27) | (uniqueChars << 1) | canChange;
        if(dp.count(key)) return dp[key];

        int charIdx = s[idx] - 'a';
        ll updatedUniqueChars = uniqueChars | (1 << charIdx);
        int uniqueCount = __builtin_popcountll(updatedUniqueChars);
        int res = 0;

        if(uniqueCount > k) {
            res = 1 + solve(s, k, idx+1, 1 << charIdx, canChange);
        }
        else {
            res = solve(s, k, idx+1, updatedUniqueChars, canChange);
        }

        // try all possibilties if possible
        if(canChange) {
            for(int newCharIdx = 0; newCharIdx < 26; newCharIdx++) {
                ll newSet = uniqueChars | (1 << newCharIdx);
                int newCount = __builtin_popcount(newSet);
                int opt = 0;
                if(newCount > k) {
                    opt = 1 + solve(s, k, idx+1, 1 << newCharIdx, !canChange);
                }
                else {
                    opt = solve(s, k, idx+1, newSet, !canChange);
                }

                res = max(res, opt);
            }
        } 

        return dp[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + solve(s, k, 0, 0, 1);
    }
};