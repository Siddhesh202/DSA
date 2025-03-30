class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // median is the target
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> vec;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                vec.push_back(grid[i][j]);
        }

        int L = vec.size();
        nth_element(vec.begin(), vec.begin() + L/2, vec.end());

        int target = vec[L/2];

        for(int i = 0; i < L; i++) {
            if((vec[i] % x) != (target % x)) 
                return -1;
            
            ans += abs(target - vec[i]) / x;
        }

        return ans;
    }
};