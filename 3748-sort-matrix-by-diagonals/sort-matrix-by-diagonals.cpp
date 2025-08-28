class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int d = i - j;
                mp[d].push_back(grid[i][j]);
            }
        }

        // Now sort
        for(auto &p : mp) {
            auto &list = p.second;

            if(p.first < 0) 
                sort(list.begin(), list.end());
            else
                sort(list.begin(), list.end(), greater<int>());
        }

        // put them back in the grid
        unordered_map<int,int> idx;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int d = i - j;
                grid[i][j] = mp[d][idx[d]++];
            }
        }


        return grid;
    }
};