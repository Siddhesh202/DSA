class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // 1. Apply Difference Array
        for(auto &query : queries) {
            int r1 = query[0], c1 = query[1];
            int r2 = query[2], c2 = query[3];

            for(int i = r1; i <= r2; i++) {
                mat[i][c1]++;
                if(c2+1 < n) mat[i][c2+1]--;
            }
        }

        // 2. Make cumSum arr
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                mat[i][j] += mat[i][j-1];
            }
        }

        return mat;
    }
};

// (row, col) => row*n + col
// row = val / size
// col = val % size