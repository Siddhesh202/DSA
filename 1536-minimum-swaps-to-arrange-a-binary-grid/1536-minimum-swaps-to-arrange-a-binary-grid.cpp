class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), steps = 0;
        vector<int> endZeros(n, 0);

        //  Get ending zeros for each row
        for(int row = 0; row < n; row++) {
            int cnt = 0;
            for(int col = n-1; col >= 0; col--) {
                if(grid[row][col] == 1) break;
                cnt++;
            }
            endZeros[row] = cnt;
        }

        // Swap rows
        for(int row = 0; row < n; row++) {
            
            int need = n - row - 1;

            int j = row;

            while(j < n && endZeros[j] < need) {
                j++;
            }

            if(j >= n) return -1;

            steps += (j-row);

            while(j > row) {
                swap(endZeros[j], endZeros[j-1]);
                j--;
            }
        }

        return steps;
    }
};

// endZeros: [0, 1, 2]
// no of zeros required in end for a row >= (n - row - 1)