#define MOD 1000000007
class Solution {
public:
    int n;
    int dp[201][201][2];
    int solve(int zeroLeft, int oneLeft, bool lastWasOne, int limit) {
        if(zeroLeft == 0 && oneLeft == 0) return 1;

        if(dp[zeroLeft][oneLeft][lastWasOne] != -1) return dp[zeroLeft][oneLeft][lastWasOne];

        int ans = 0;
        if(lastWasOne) { // Explore 0's num
            for(int len = 1; len <= min(zeroLeft, limit); len++) {
                ans = (ans + solve(zeroLeft - len, oneLeft, false, limit)) % MOD;
            } 
        }
        else {
            for(int len = 1; len <= min(oneLeft, limit); len++) {
                ans = (ans + solve(zeroLeft, oneLeft - len, true, limit)) % MOD;
            } 
        }

        return dp[zeroLeft][oneLeft][lastWasOne] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        n = zero+one;
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        ans = (ans + solve(zero, one, false, limit)) % MOD;
        ans = (ans + solve(zero, one, true, limit)) % MOD;

        return ans;
    }
};

// saare arrs dhundho eg [1,0,1,0,0,1], .... -----> O(n^2)
// each arr mai subarrs ka condition check karo --> O(n^2) --> Can be optimized ---> 
// Can I find a subarr of len atleast (limit + 1) with same consecutive elems eg 111, 0000, ...  ---> Can be done in O(n)
// Can go max TC = O(n^3)
// Right now I am getting TC = O(n^4)