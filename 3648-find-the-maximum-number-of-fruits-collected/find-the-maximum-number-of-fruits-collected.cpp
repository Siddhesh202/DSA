class Solution {
public:
    int n;
    vector<vector<int>> dirs2 = {{1,-1}, {1,0}, {1,1}};
    vector<vector<int>> dirs3 = {{-1,1}, {0,1}, {1,1}};
    vector<vector<int>> dp2, dp3;

    int solve2(vector<vector<int>>& fruits, int i, int j) {
        if(i >= n || j >= n || i < 0 || j < 0 || i > j) {
            return 0;
        }

        if(dp2[i][j] != -1) return dp2[i][j];

        int ans = 0;
        for(auto &dir : dirs2) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            ans = max(solve2(fruits, newi, newj), ans);
        }

        return dp2[i][j] = fruits[i][j] + ans;
    }

    int solve3(vector<vector<int>>& fruits, int i, int j) {
        if(i >= n || j >= n || i < 0 || j < 0 || i < j) {
            return 0;
        }

        if(dp3[i][j] != -1) return dp3[i][j];

        int ans = 0;
        for(auto &dir : dirs3) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            ans = max(solve3(fruits, newi, newj), ans);
        }

        return dp3[i][j] = fruits[i][j] + ans;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp2.assign(n, vector<int>(n,-1));
        dp3.assign(n, vector<int>(n,-1));
        int child1 = 0, child2 = 0, child3 = 0;

        for(int i = 0; i < n; i++) {
            child1 += fruits[i][i];
            fruits[i][i] = 0;
        }

        child2 = solve2(fruits, 0, n-1);
        child3 = solve3(fruits, n-1, 0);

        return child1 + child2 + child3;
    }
};