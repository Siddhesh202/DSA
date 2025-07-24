class Solution {
public:
    int n, time;
    vector<int> xorsubtree, inTime, outTime;

    void dfs(unordered_map<int,vector<int>> &adj, int node, int parent) {
        inTime[node] = time;
        time++;

        for(auto &adjNode : adj[node]) {
            
            if(adjNode != parent) {
                dfs(adj, adjNode, node);
                xorsubtree[node] ^= xorsubtree[adjNode];
            }
        }

        outTime[node] = time;
        time++;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        time = 0;
        unordered_map<int,vector<int>> adj;
        xorsubtree.assign(n, 0);
        inTime.assign(n, 0);
        outTime.assign(n, 0);

        // 1. Create the graph
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2. Calc xor subtree as well as inTime and outTime
        for(int i = 0; i < n; i++) xorsubtree[i] = nums[i];
        dfs(adj, 0, -1);

        // 3. calc all poss using node1 and node2
        int result = INT_MAX;
        for(int node1 = 1; node1 < n; node1++) {
            for(int node2 = node1+1; node2 < n; node2++) {
                int xor1, xor2, xor3;
                // check if node1 is ancestor of node2
                if(inTime[node1] <= inTime[node2] && outTime[node2] <= outTime[node1]) {
                    xor1 = xorsubtree[node1] ^ xorsubtree[node2];
                    xor2 = xorsubtree[node2];
                    xor3 = xorsubtree[0] ^ xor1 ^ xor2;
                }
                else if(inTime[node2] <= inTime[node1] && outTime[node1] <= outTime[node2]) { // check if node2 is ancestor of node1
                    xor1 = xorsubtree[node1];
                    xor2 = xorsubtree[node2] ^ xorsubtree[node1];
                    xor3 = xorsubtree[0] ^ xor1 ^ xor2;
                }
                else {
                    xor1 = xorsubtree[node1];
                    xor2 = xorsubtree[node2];
                    xor3 = xorsubtree[0] ^ xor1 ^ xor2;
                }

                result = min(result, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));

            }
        }

        return result;
    }
};