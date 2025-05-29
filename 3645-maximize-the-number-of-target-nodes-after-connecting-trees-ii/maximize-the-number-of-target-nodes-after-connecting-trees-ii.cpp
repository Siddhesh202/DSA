class Solution {
public:
    int n, m;
    int zeroCnt;
    void dfs(unordered_map<int, vector<int>> &adj, int node, int currNodeKaParent, vector<int>& mark, int& zeroMarkCnt, int& oneMarkCnt) {
        if(mark[node] == 0) 
            zeroMarkCnt++;
        else 
            oneMarkCnt++;

        for(auto &adjNode: adj[node]) {
            if(adjNode != currNodeKaParent) {
                mark[adjNode] = !mark[node];
                dfs(adj, adjNode, node, mark, zeroMarkCnt, oneMarkCnt);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n = edges1.size()+1;
        m = edges2.size()+1;
        zeroCnt = 0;
        vector<int> markA(n, -1), markB(m, -1), ans(n, 0);
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
        int zeroMarkedCntA = 0;
        int oneMarkedCntA = 0;
        dfs(adj1, 0, -1, markA, zeroMarkedCntA, oneMarkedCntA);

        int zeroMarkedCntB = 0;
        int oneMarkedCntB = 0;
        dfs(adj2, 0, -1, markB, zeroMarkedCntB, oneMarkedCntB);

        for(int i = 0; i < n; i++) {
            if(markA[i] == 0) ans[i] += zeroMarkedCntA;
            else ans[i] += oneMarkedCntA;

            ans[i] += max(zeroMarkedCntB, oneMarkedCntB);
        }

        return ans;
    }
};