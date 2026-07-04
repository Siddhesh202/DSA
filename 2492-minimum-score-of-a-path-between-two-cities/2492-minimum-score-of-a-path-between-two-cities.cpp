class Solution {
public:
    vector<int> parent, rank;

    void Union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;

        if(rank[pa] < rank[pb]) 
            parent[pa] = pb;
        else if(rank[pb] < rank[pa]) 
            parent[pb] = pa;
        else {
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for(int i = 1; i <= n; i++) parent[i] = i;

        // create a DSU
        for(auto &road : roads) Union(road[0], road[1]);

        // Now find mini
        int root = find(1);
        int ans = INT_MAX;

        for(auto &road : roads) {
            if(find(road[0]) == root) ans = min(ans, road[2]);
        }

        return ans;
    }
};