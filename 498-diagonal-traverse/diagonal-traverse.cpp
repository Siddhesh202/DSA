class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        
        for(auto &p : mp) {

            if(flip) {
                reverse(p.second.begin(), p.second.end());
            }

            for(auto &num : p.second) {
                ans.push_back(num);
            }

            flip = !flip;
        }

        return ans;
    }
};