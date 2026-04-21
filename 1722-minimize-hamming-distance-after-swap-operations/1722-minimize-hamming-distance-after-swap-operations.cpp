class Solution {
public:
    void Union(vector<int> &parent, vector<int> &rank, int x, int y) {
        int parent_x = find(parent, x);
        int parent_y = find(parent, y);

        if(parent_x == parent_y) return;

        if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }else if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    int find(vector<int> &parent, int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), res = 0;
        vector<int> parent(n), rank(n, 0);
        unordered_map<int,unordered_map<int,int>> component;

        for(int i = 0; i < n; i++) parent[i] = i;

        // Create DSU by iterating over allowed swaps
        for(auto &swaps : allowedSwaps) {
            int x = swaps[0], y = swaps[1];
            Union(parent, rank, x, y);
        }

        for(int i = 0; i < n; i++) {
            int comp = find(parent, i);
            component[comp][source[i]]++;
        }


        for(int i = 0; i < n; i++) {
            int src = source[i], tar = target[i];
            int par = find(parent, i);

            if(component[par].count(tar) && component[par][tar] > 0) {
                component[par][tar]--;
            }
            else res++;
            
        }

        return res;


    }
};

// 1 2 3 4
// 2 1 4 5 

// allowed swaps = (0,1), (2,3)
// galat positions =  

// 5 1 2 4 3
// 1 5 4 2 3

// 0 - 4 - 2 - 1 - 3
// hamming distance = 0