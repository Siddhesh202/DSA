class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &adj, int node, int k, int currNodeKaParent) {
        if(k < 0) return 0;
        if(k == 0) return 1;
        int ans = 1;

        for(auto &adjNode: adj[node]) {
            if(adjNode != currNodeKaParent) {
                ans += dfs(adj, adjNode, k-1, node);
            }
        }

        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<int> res(n, 0);
        unordered_map<int, vector<int>> adj1, adj2;
        int maxi = 0;

        // make adj list for both edges
        for(auto &edge: edges1) {
            int u = edge[0];
            int v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto &edge: edges2) {
            int u = edge[0];
            int v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // Find shortest dist in same tree
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            res[i] = dfs(adj1, i, k, -1);
        }

        // Find dist in other tree with max count
        for(int i = 0; i < m; i++) {
            vector<bool> visited(n, false);
            maxi = max(dfs(adj2, i, k-1, -1), maxi);
        }

        for(int i = 0; i < n; i++) {
            res[i] += maxi;
        }

        return res;
    }
};