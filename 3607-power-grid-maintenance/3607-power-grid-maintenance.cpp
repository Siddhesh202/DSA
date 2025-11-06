class Solution {
public:
    void dfs(int node, int component, vector<int> &componentId, unordered_map<int, set<int>> &mp, vector<int> &visited, unordered_map<int,vector<int>> &adj) {
        visited[node] = true;
        componentId[node] = component;
        mp[component].insert(node);

        for(auto &adjNode : adj[node]) {
            if (!visited[adjNode]) dfs(adjNode, component, componentId, mp, visited, adj);
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<int> visited(c+1, 0), componentId(c+1);
        unordered_map<int, set<int>> mp;
        vector<int> ans;

        // 1. Create graph
        for(auto &con : connections) {
            int u = con[0];
            int v = con[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2. do the dfs and mark konse component ka kaun hai
        for(int i = 1; i <= c; i++) {
            if(!visited[i]) {
                dfs(i, i, componentId, mp, visited, adj);
            }
        }

        // 3. Now process the queries
        for(auto &query : queries) {
            int queryId = query[0];
            int node = query[1];
            int compId = componentId[node];

            if(queryId == 1) {
                if(mp[compId].empty()) ans.push_back(-1);
                else if(mp[compId].find(node) != mp[compId].end()) ans.push_back(node);
                else ans.push_back(*(mp[compId].begin()));
            }
            else {
                mp[compId].erase(node);
            }
        }

        return ans;
    }
};