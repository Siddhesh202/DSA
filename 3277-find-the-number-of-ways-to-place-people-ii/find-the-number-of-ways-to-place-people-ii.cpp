class Solution {
public:
    bool checkRect(int x1, int y1, int x2, int y2, int px, int py) {
        int a = min(x1, x2);
        int b = max(x1, x2);
        int c = min(y1, y2);
        int d = max(y1, y2);

        return (px < a || px > b || py < c || py > d);
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        // if(n == 2) return 1;

        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        for(int i = 0; i < n; i++) {

            int maxY = INT_MIN;

            for(int j = i+1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y1 < y2) continue;
                    
                if(maxY < y2) {
                    ans++;
                    maxY = y2;
                } 
            }
        }

        return ans;
    }
};