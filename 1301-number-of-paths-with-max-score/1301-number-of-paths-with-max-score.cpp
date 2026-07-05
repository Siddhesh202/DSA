#define MOD 1000000007
#define ll long long

class Solution {
public:
    int n;
    vector<vector<pair<ll, ll>>> dp;
    vector<vector<bool>> vis;

    pair<ll, ll> solve(vector<vector<char>> &grid, int i, int j) {
        // Out of bounds or obstacle
        if (i < 0 || j < 0 || grid[i][j] == 'X')
            return {LLONG_MIN, 0};

        // Reached destination
        if (i == 0 && j == 0)
            return {0, 1};

        // Already computed
        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        ll bestScore = LLONG_MIN;
        ll bestPaths = 0;

        // From top
        auto [upScore, upPaths] = solve(grid, i - 1, j);
        if (upScore != LLONG_MIN) {
            if (upScore > bestScore) {
                bestScore = upScore;
                bestPaths = upPaths;
            } else if (upScore == bestScore) {
                bestPaths = (bestPaths + upPaths) % MOD;
            }
        }

        // From left
        auto [leftScore, leftPaths] = solve(grid, i, j - 1);
        if (leftScore != LLONG_MIN) {
            if (leftScore > bestScore) {
                bestScore = leftScore;
                bestPaths = leftPaths;
            } else if (leftScore == bestScore) {
                bestPaths = (bestPaths + leftPaths) % MOD;
            }
        }

        // From diagonal
        auto [diagScore, diagPaths] = solve(grid, i - 1, j - 1);
        if (diagScore != LLONG_MIN) {
            if (diagScore > bestScore) {
                bestScore = diagScore;
                bestPaths = diagPaths;
            } else if (diagScore == bestScore) {
                bestPaths = (bestPaths + diagPaths) % MOD;
            }
        }

        if (bestScore == LLONG_MIN)
            return dp[i][j] = {LLONG_MIN, 0};

        return dp[i][j] = {
            bestScore + (grid[i][j] - '0'),
            bestPaths % MOD
        };
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        vector<vector<char>> grid(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = board[i][j];
            }
        }

        // Don't count S and E
        grid[0][0] = '0';
        grid[n - 1][n - 1] = '0';

        dp.assign(n, vector<pair<ll, ll>>(n));
        vis.assign(n, vector<bool>(n, false));

        auto [score, paths] = solve(grid, n - 1, n - 1);

        if (score == LLONG_MIN)
            return {0, 0};

        return {(int)score, (int)(paths % MOD)};
    }
};