class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x;
        int j = i + k - 1;

        while(i < j) {
            for(int col = y; col <= y + k - 1; col++) {
                int temp = grid[i][col];
                grid[i][col] = grid[j][col];
                grid[j][col] = temp;
            }

            i++;
            j--;
        }

        return grid;
    }
};