#define P pair<int,int>
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int countWalls(vector<int>& walls, int left, int right) {
        return upper_bound(walls.begin(), walls.end(), right) - lower_bound(walls.begin(), walls.end(), left);
    }

    int solve(vector<int>& walls, vector<P> &roboDist, vector<P> &range, int idx, int prev)  // prev can be 0 -> L, 1 -> R
    {
        if(idx >= n) return 0;

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int leftStart = range[idx].first, rightEnd = range[idx].second;
        
        if(prev == 1 && idx > 0) leftStart = max(leftStart, range[idx-1].second+1);

        // try left
        int left = countWalls(walls, leftStart, roboDist[idx].first) + solve(walls, roboDist, range, idx+1, 0);

        // try right
        int right = countWalls(walls, roboDist[idx].first, rightEnd) + solve(walls, roboDist, range, idx+1, 1);

        return dp[idx][prev] = max(left, right);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        vector<P> roboDist;
        vector<P> range;

        for(int i = 0; i < n; i++) roboDist.push_back({robots[i], distance[i]});

        // Sort roboDist and walls
        sort(roboDist.begin(), roboDist.end());
        sort(walls.begin(), walls.end());

        // Find range of each robot
        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)   ? 1   : roboDist[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first-1;

            int L = max(pos - d, leftLimit);
            int R = min(pos + d, rightLimit);

            range.push_back({L,R});
        }

        // Apply DP with BS now
        dp.assign(n+1, vector<int>(2, -1));
        return solve(walls, roboDist, range, 0, 0);
        
    }
};

// I can do dp after sorting
// [(2,1),(10,5)] ---> pos,dist
// [2,5,7] ---> walls
// So dp would be for idx ,prevDecision
// prev decision matters because if prev robot chose to go right, curr robot has only the option to go right
// if  prev robot chose to go left, my current robot has an option to go both left and right