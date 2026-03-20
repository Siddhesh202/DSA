class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j, int k) {
        int ans = INT_MAX;
        set<int> st;

        for(int row = i; row <= i + k - 1; row++) {
            for(int col = j; col <= j + k - 1; col++) {
                st.insert(grid[row][col]);
            }
        }

        if(st.size() == 1) return 0;

        auto prev = st.begin();
        auto curr = next(st.begin());

        while(curr != st.end()) {
            ans = min(ans, abs(*prev - *curr));
            prev = curr;
            curr++;
        }

        return ans;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for(int row = 0; row <= m - k; row++) {
            for(int col = 0; col <= n - k; col++) {
                ans[row][col] = solve(grid, row, col, k);
            }
        }

        return ans;
    }
};