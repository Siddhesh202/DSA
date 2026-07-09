class Solution {
public:
    vector<int> parent, rank;
    void Union(int a, int b) {
        int px = find(a);
        int py = find(b);

        if(rank[px] > rank[py]) parent[py] = px;
        else if(rank[py] > rank[px]) parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        vector<bool> ans;

        for(int i = 0; i < n; i++) parent[i] = i;

        // Create DSU
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff)
                Union(i, i + 1);
        }

        // process queries
        for(auto &query : queries) {
            int px = find(query[0]);
            int py = find(query[1]);

            if(px == py) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};