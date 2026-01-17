#define ll long long
class Solution {
public:
    bool checkIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        bool a = max(x1, x3) < min(x2, x4);
        bool b = max(y1, y3) < min(y2, y4);
        return a & b;
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll ans = 0;

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {

                int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1], x2 = topRight[i][0], y2 = topRight[i][1];
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1], x4 = topRight[j][0], y4 = topRight[j][1];

                if(checkIntersect(x1, y1, x2, y2, x3, y3, x4, y4)) {

                    int a = max(x1, x3), c = min(x2, x4);
                    int b = max(y1, y3), d = min(y2, y4);

                    int width = abs(c-a);
                    int height = abs(d-b);

                    ll side = min(width, height);
                    ll currArea = (side * side);

                    ans = max(ans, currArea);
                }
            }
        }

        return ans;
    }
};