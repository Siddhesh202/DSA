class Solution {
public:
    int mini = INT_MAX;
    void dfs(unordered_map<int,vector<vector<int>>> &adj, vector<bool> &visited, int node) {
        visited[node] = true;
        
        for(auto &neig: adj[node]) {
            int adjNode = neig[0];
            int dist = neig[1];

            if(!visited[adjNode]) dfs(adj, visited, adjNode);
            mini = min(mini, dist);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>> adj;
        vector<bool> visited(n+1, false);

        for(auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        dfs(adj, visited, 1);
        return mini;
    }
};