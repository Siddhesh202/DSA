class Solution {
public:
    void Union(int x, int y, vector<int> &parent, vector<int> &rank, vector<int> &size) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent)
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        else if(rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
            size[x_parent] += size[y_parent];
        }
    }

    int find(int x, vector<int> &parent) {
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x], parent);
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0), rank(n,0), size(n,1);
        unordered_map<int, int> edgeCount;

        for(int i = 0; i < n; i++) {
            parent[i] = i;  // Each node is its own parent initially
        }
        
        // create dsu
        for(auto &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            Union(x, y, parent, rank, size);
        }

        // Calculate total edges for each component
        for(auto &edge : edges) {
            int root = find(edge[0], parent);
            edgeCount[root]++;
        }

        // check if each component is complete
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(find(i, parent) == i) { // matlab root hai
                int compEdges = edgeCount[i];
                int nodes = size[i];
                if(compEdges == (nodes * (nodes-1) / 2))
                    ans++;
            }
        }

        return ans;
    }
};