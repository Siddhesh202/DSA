class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dirs = {{0,1}, {0, -1}, {1,0}, {-1,0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        ans[0][0] = 0;
        pq.push({0, 0, 0});

        while(!pq.empty()) {
            auto &v = pq.top();
            int currTime = v[0];
            int i = v[1];
            int j = v[2];
            pq.pop();

            for(auto &dir : dirs) {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi >= 0 && newi < n && newj >= 0 && newj < m) {
                    int wait = (currTime < moveTime[newi][newj]) ? moveTime[newi][newj] - currTime : 0;
                    if(wait + currTime + 1 < ans[newi][newj]) {
                        pq.push({ wait+currTime+1, newi, newj });
                        ans[newi][newj] = wait+currTime+1;
                    }
                }
            }
        }

        return ans[n-1][m-1];
    }
};