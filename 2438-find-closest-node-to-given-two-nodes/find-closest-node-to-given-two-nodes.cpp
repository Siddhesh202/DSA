class Solution {
public:
    void dfs(vector<int>& edges, vector<int>& res, int node, int lvl) {
        res[node] = lvl;

        if(edges[node] != -1 && res[edges[node]] == INT_MAX) 
            dfs(edges, res, edges[node], lvl+1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> resA(n, INT_MAX), resB(n, INT_MAX);
        int ans = INT_MAX, ansNode;
        resA[node1] = 0, resB[node2] = 0;

        dfs(edges, resA, node1, 0);
        dfs(edges, resB, node2, 0);

        for(int i = 0; i < n; i++) {
            int potAns = max(resA[i], resB[i]);
            if(potAns < ans) {
                ans = potAns;
                ansNode = i;
            }
        }


        return ans == INT_MAX ? -1 : ansNode;
    }
};