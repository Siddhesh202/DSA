class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> arr = mat;

        k %= cols; // Reduce k to k%cols
        if(k == 0) return true;

        // Check what happens if there are duplicates and how to handle it
        vector<vector<int>> temp = arr;
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                // For even no rows, do a cyclic left
                if(row%2) temp[row][(col-k+cols)%cols] = arr[row][col];

                // For odd rows, do a cyclic right
                else temp[row][(col+k)%cols] = arr[row][col];
            }
        }

        arr = temp;

        return arr == mat;
    }
};