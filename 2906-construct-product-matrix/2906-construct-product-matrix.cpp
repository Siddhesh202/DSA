#define MOD 12345
#define ll long long
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1));
        ll lp = 1, rp = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = lp;
                lp *= grid[i][j]; 
                lp %= MOD;
            }
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                res[i][j] *= rp;
                res[i][j] %= MOD;
                rp *= grid[i][j];
                rp %= MOD;
            }
        }

        return res;
    }
};