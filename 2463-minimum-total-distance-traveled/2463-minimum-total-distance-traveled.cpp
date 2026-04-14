class Solution {
    #define MAX 10000000000000LL
    using ll = long long;
public:
    long long f(vector<int>& robot, vector<int>& factories, int i, int j, vector<vector<ll>>& dp)
    {
        if(i < 0)
            return 0;
        
        if(j < 0)
            return MAX;

        if(dp[i][j] != -1)
            return dp[i][j];

        ll exclude = f(robot, factories, i, j-1, dp);

        ll include = abs(factories[j] - robot[i]) + f(robot, factories, i-1, j-1, dp);

        return dp[i][j] = min(exclude, include);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories;

        for(int i = 0; i < factory.size(); i++)
        {
            int pos = factory[i][0];
            int limit = factory[i][1];

            for(int l = 1; l <= limit; l++) {
                factories.push_back(pos);
                // cout << pos << " ";
            }
        }

        int m = robot.size();
        int n = factories.size();
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -1));

        return f(robot, factories, m-1, n-1, dp);
    }
};