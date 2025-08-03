class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int P, int k) {
        int n = fruits.size();
        int maxFruits = 0;
        vector<int> prefSum(n, 0), positions(n);
        
        // Create a prefix sum
        prefSum[0] = fruits[0][1];
        positions[0] = fruits[0][0];
        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + fruits[i][1]; 
            positions[i] = fruits[i][0];
        }

        // Go for 2 cases with range d
        for(int d = 0; d <= k/2; d++) {
            int i, j;

            // Case 1 - (Left -> Right)
            i = (P - d);
            j = P + (k - 2 * d);

            int leftPos = lower_bound(begin(positions), end(positions), i) - begin(positions);
            int rightPos = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if(leftPos <= rightPos) 
            maxFruits = max(maxFruits, prefSum[rightPos] - (leftPos > 0 ? prefSum[leftPos-1] : 0));

            // Case 2 - (Right -> Left)
            i = P - (k - 2 * d);
            j = P + d;

            leftPos = lower_bound(begin(positions), end(positions), i) - begin(positions);
            rightPos = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if(leftPos <= rightPos) 
            maxFruits = max(maxFruits, prefSum[rightPos] - (leftPos > 0 ? prefSum[leftPos-1] : 0));
        }

        return maxFruits;
    }
};