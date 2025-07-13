#define P pair<int,int>
class Solution {
public:
    void dfs(unordered_map<int,vector<P>> &adj, int node, int tar, vector<bool> &visited) {
        visited[node] = true;

        for(auto &neig : adj[node]) {
            int adjNode = neig.first;
            int value   = neig.second;

            if(!visited[adjNode] && value <= tar) 
                dfs(adj, adjNode, tar, visited);
        }
    }

    bool isPossible(unordered_map<int,vector<P>> &adj, int tar, int k, int n) {
        int numComp = 0;
        vector<bool> visited(n, 0);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, i, tar, visited);
                numComp++;
            }
        }

        return numComp <= k;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        unordered_map<int,vector<P>> adj;
        int l = 0, r = 0, ans;

        // 1. Create a Adj Matrix
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            r = max(r, wt);

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // 2. Do Binary Search
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(isPossible(adj, mid, k, n)) { // 3. Count no of components for that mid
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        return ans;
    }
};