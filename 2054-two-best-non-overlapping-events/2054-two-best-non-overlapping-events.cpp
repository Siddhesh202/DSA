class Solution {
public:
    int n;
    int dp[100001][3];

    int binarySearch(vector<vector<int>>& events, int target) {
        int l = 0, r = n-1, ans = n;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(events[mid][0] > target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int solve(vector<vector<int>>& events, int idx, int cnt) {
        if(idx >= n || cnt == 2) return 0;

        if(dp[idx][cnt] != -1) return dp[idx][cnt];

        // take
        int nextIdx = binarySearch(events, events[idx][1]);
        int take = events[idx][2] + solve(events, nextIdx, cnt+1);

        // no take
        int notake = solve(events, idx+1, cnt);

        return dp[idx][cnt] = max(take, notake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));

        return solve(events, 0, 0);
    }
};