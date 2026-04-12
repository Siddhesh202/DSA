class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};