class Solution {
public:
    int n;
    int dp[1001];
    int solve(vector<int>& arr, int i, int d) {
        
        if(dp[i] != -1) return dp[i];

        int left = 0, right = 0;

        // solve for left
        for(int j = i-1; j >= max(0, i-d); j--) {
            if(arr[j] >= arr[i]) break;
            left = max(left, solve(arr, j, d));
        }

        // solve for right
        for(int j = i+1; j <= min(n-1, i+d); j++) {
            if(arr[j] >= arr[i]) break;
            right = max(right, solve(arr, j, d));
        }

        return dp[i] = 1 + max(left, right);
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, i, d));
        }

        return ans;
    }
};