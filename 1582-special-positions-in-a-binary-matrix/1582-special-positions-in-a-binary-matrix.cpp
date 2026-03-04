class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> rowOnes(m, 0), colOnes(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1 && rowOnes[i] == 1 && colOnes[j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// rowOnes = [1, 1, 1]
// colOnes = [2, 0, 1]

// rowOnes = [1, 0, 0, 1]
// colOnes = [0, 1, 1, 0]

// 0 0 1 0
// 0 0 0 0
// 0 0 0 0
// 0 1 0 0