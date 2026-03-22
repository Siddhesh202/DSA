class Solution {
public:
    int n;
    void transpose(vector<vector<int>>& mat) {
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) swap(mat[i][j], mat[j][i]);
        }
    }

    void rowReverse(vector<vector<int>>& mat) {
        for(int i = 0; i < n; i++) reverse(mat[i].begin(), mat[i].end());
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        
        for(int rot = 1; rot <= 4; rot++) {

            // Transpose and reverse row for 90 deg rotation
            transpose(mat);
            rowReverse(mat);

            // compare with target
            if(mat == target) return true;
        }

        return false;
    }
};