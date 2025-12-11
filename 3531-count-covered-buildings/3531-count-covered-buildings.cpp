class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,set<int>> x_cor, y_cor;
        int ans = 0;

        for(auto &build : buildings) {
            int x = build[0];
            int y = build[1];

            y_cor[y].insert(x);
            x_cor[x].insert(y);
        }

        for(auto &build : buildings) {
            int x = build[0];
            int y = build[1];
            int minx = *(y_cor[y].begin());
            int maxx = *(y_cor[y].rbegin());
            int miny = *(x_cor[x].begin());
            int maxy = *(x_cor[x].rbegin());

            // check for conditions now
            if(minx < x && maxx > x && miny < y && maxy > y) ans++;
        }

        return ans;
    }
};