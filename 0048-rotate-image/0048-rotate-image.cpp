class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // For 90 Deg Rotation - Transpose + Reverse
        
        // 1. Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. Reverse
        for(int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};