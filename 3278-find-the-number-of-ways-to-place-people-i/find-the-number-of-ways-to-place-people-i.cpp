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

        sort(points.begin(), points.end());

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if((x1 <= x2 && y1 >= y2) || (x2 <= x1 && y2 >= y1)) {
                    bool isValid = true;
                    for(int k = 0; k < n; k++) {
                        if(k == i || k == j) continue;

                        int px = points[k][0];
                        int py = points[k][1];

                        if(!checkRect(x1, y1, x2, y2, px, py))
                        {
                            isValid =false;
                            break;
                        }
                    }

                    if(isValid) ans++;
                }
            }
        }

        return ans;
    }
};