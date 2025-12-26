class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> leftN(n), rightY(n);

        for(int i = 0; i < n; i++) {
            leftN[i] = (i > 0 ? leftN[i-1] : 0) + (customers[i] == 'N');
        }

        for(int i = n-1; i >= 0; i--) {
            rightY[i] = (i < n-1 ? rightY[i+1] : 0) + (customers[i] == 'Y');
        }

        int ans = INT_MAX, ansIdx = 0;

        // check all closing times 0..n
        for(int i = 0; i <= n; i++) {
            int penalty =
                (i > 0 ? leftN[i-1] : 0) +
                (i < n ? rightY[i] : 0);

            if(penalty < ans) {
                ans = penalty;
                ansIdx = i;
            }
        }

        return ansIdx;
    }
};