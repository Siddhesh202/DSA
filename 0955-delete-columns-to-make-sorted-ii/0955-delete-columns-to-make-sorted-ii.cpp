class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int rows = strs.size(), cols = strs[0].length(); // m --> rows , n --> cols
        vector<bool> resolved(rows, 0);

        for(int col = 0; col < cols; col++) {
            bool bad = false;
            vector<bool> newResolved = resolved;

            for (int row = 0; row < rows - 1; row++) {
                if (!resolved[row]) {
                    if (strs[row][col] > strs[row + 1][col]) {
                        bad = true;
                        break;
                    } 
                    else if (strs[row][col] < strs[row + 1][col]) {
                        newResolved[row] = true;
                    }
                }
            }

            if (bad) {
                ans++;            // delete column
            } else {
                resolved = newResolved; // commit progress
            }
        }

        return ans;
    }
};

// 3 cases hai
// Case 1: Entire column is sorted --> break, no need to delete any more columns
// Case 2: Entire column is sorted but contains some duplicates --> need to check order for these rows only in next columns
// Case 3: Column is not sorted ---> delete it