#define ll long long
#define P pair<int,long long>
class Solution {
public:
    const int MOD = 1e9+7;
    int n;
    vector<int> BFS(unordered_map<int,vector<P>> &adj) {
        vector<int> ans(n, 1);
        queue<P> q;
        vector<bool> visited(n, false);
        q.push({0, 1});
        visited[0] = true;

        while(!q.empty()) {
            int node = q.front().first;
            ll cost = q.front().second;
            q.pop();

            ans[node] = cost;
            
            for(auto &adj : adj[node]) {
                int adjNode = adj.first;
                ll wt = adj.second;
                if(!visited[adjNode]) {
                    q.push({adjNode, (((cost % MOD) * (wt % MOD)) % MOD) });
                    visited[adjNode] = true;
                }
            }
        }

        return ans;
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        n = conversions.size() + 1;
        unordered_map<int,vector<P>> adj;

        // create a map
        for(auto &conv : conversions) {
            int u = conv[0];
            int v = conv[1];
            int wt = conv[2];

            adj[u].push_back({v, wt});
        }

        return BFS(adj);
    }
};