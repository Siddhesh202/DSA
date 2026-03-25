#define ll long long
class Solution {
public:

    // TC - O(3*n)
    // SC - O(1)
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll total = 0, m = grid.size(), n = grid[0].size();

        // Get total sum
        for(int row = 0; row < m; row++) {
            for(int col = 0; col< n; col++) {
                total += grid[row][col];
            } 
        }

        if(total % 2) return false;

        // Try for horizontal cuts
        ll horiSum = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col< n; col++) {
                horiSum += grid[row][col];
            } 

            if(horiSum == (total - horiSum)) return true;
        }

        // Try for vertical cuts
        ll vertSum = 0;
        for(int col = 0; col < n; col++) {
            for(int row = 0; row < m; row++) {
                vertSum += grid[row][col];
            } 

            if(vertSum == (total - vertSum)) return true;
        }

        return false;
    }
};