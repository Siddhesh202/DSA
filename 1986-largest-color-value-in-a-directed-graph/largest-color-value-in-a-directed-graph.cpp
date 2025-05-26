class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        unordered_map<int,vector<int>> graph;
        vector<int> indeg(n, 0);
        queue<int> q;
        int ans = 0, countNodes = 0;

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indeg[v]++;
        }

        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) { 
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        // Do topo sort now
        while(!q.empty()) {
            int node = q.front();
            int colNode = colors[node]-'a';
            countNodes++;
            q.pop();

           ans = max(ans, dp[node][colNode]);

            for(auto &adjNode : graph[node]) {
                int colAdjNode = colors[adjNode]-'a';
                for(int i = 0; i < 26; i++) {
                    int toAdd = (colAdjNode == i) ? 1 : 0;
                    dp[adjNode][i] = max(dp[adjNode][i], dp[node][i] + toAdd);
                }
                indeg[adjNode]--;
                if(indeg[adjNode] == 0) q.push(adjNode);
            }
        }

        if(countNodes < n) return -1;

        return ans;
    }
};