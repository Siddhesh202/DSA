#define P pair<int,int>
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> adj;
        vector<int> ans(n, INT_MAX);
        priority_queue<P, vector<P>, greater<>> pq;
        ans[0] = 0;
        pq.push({0, 0});

        // Create an adjacency list
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int e = it[3];

            adj[u].push_back({v, s, e});
        }

        while(!pq.empty()) {
            int currTime = pq.top().first;
            int node     = pq.top().second;
            pq.pop();

            for(auto &it: adj[node]) {
                int adjNode = it[0];
                int start = it[1];
                int end = it[2];

                if(currTime > end) continue;
                int time = max(currTime, start) + 1;

                if(time < ans[adjNode]) {
                    ans[adjNode] = time;
                    pq.push({time, adjNode});
                }
            }
        }

        for(auto &val : ans)
            cout << val << ", ";

        if(ans[n-1] == INT_MAX) return -1;

        return ans[n-1];  
    }
};