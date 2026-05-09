class Solution {
public:

    vector<int> createArray(vector<vector<int>>& grid, int rs, int re, int cs, int ce) {
        vector<int> ans;

        for(int i = rs; i <= re; i++) ans.push_back(grid[i][cs]);
        for(int j = cs+1; j <= ce; j++) ans.push_back(grid[re][j]);
        for(int i = re-1; i >= rs; i--) ans.push_back(grid[i][ce]);
        for(int j = ce-1; j > cs; j--) ans.push_back(grid[rs][j]);

        return ans;
    }

    vector<int> rotateKtimes(vector<int> &arr, int k) {
        int size = arr.size();
        k = (k % size);
        vector<int> temp(size);

        for(int i = 0; i < size; i++) temp[(i+k)%size] = arr[i];
        return temp;
    }

    void putBackInGrid(vector<vector<int>>& grid, vector<int> &arr, int rs, int re, int cs, int ce) {
        int k = 0;
        for(int i = rs; i <= re; i++) {grid[i][cs] = arr[k]; k++;}
        for(int j = cs+1; j <= ce; j++) {grid[re][j] = arr[k]; k++;}
        for(int i = re-1; i >= rs; i--) {grid[i][ce] = arr[k]; k++;}
        for(int j = ce-1; j > cs; j--) {grid[rs][j] = arr[k]; k++;}

    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        for(int layer = 0; layer < min(m, n) / 2; layer++) {
            int rs = layer, cs = layer;
            int re = m - layer - 1;
            int ce = n - layer - 1;

            // 1. Rotate the layer cyclically and put it in an array
            vector<int> arr = createArray(grid, rs, re, cs, ce);

            // 2. Rotate the array k times
            arr = rotateKtimes(arr, k);

            // 3. Traverse the array cylcically and put the values in the grid from the array
            putBackInGrid(grid, arr, rs, re, cs, ce);
        }

        return grid;
    }
};

// 1 8 7 6 5 4 3 2
// 2 1 8 7 6 5 4 3 (k = 1 means move 1 time to the right)
// 3 2 1 8 7 6 5 4 (k = 2 means move 2 time to the right)