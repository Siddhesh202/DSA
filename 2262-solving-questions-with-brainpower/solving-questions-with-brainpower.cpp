class Solution {
public:
    int n;
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long> dp(n+1,0);

        for(int index = n-1; index >= 0; index--) {
            long long take = questions[index][0];

            if(index + questions[index][1] + 1 < n)
                take += dp[index + questions[index][1] + 1];

            long long notake = dp[index+1];

            dp[index] = max(take, notake);
        }
        return dp[0];
    }
};