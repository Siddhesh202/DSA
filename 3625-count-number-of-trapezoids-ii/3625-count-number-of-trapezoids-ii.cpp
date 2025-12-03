class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<float, vector<float>> slopeToIntercept; // slope --> intercept --> count
        unordered_map<int, vector<float>> midToSlope;

        int res = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                float dy = (y2-y1), dx = (x2-x1);
                float slope = 0, intercept = 0;
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                
                if(x1 == x2) {
                    slope = 1e9+7;
                    intercept = x1;
                }
                else {
                    slope = (float)(y2-y1)/(x2-x1);
                    intercept = (float)(y1*dx - x1*dy) / dx;
                }

                slopeToIntercept[slope].push_back(intercept);
                midToSlope[mid].push_back(slope);
                // cout << "(" << x1 << "," << y1 << "), " << "(" << x2 << "," << y2 << ")" << " ---> " << slope << " ---> " << intercept << endl;
            }
        }

        // Now simply iterate over each slope and do parallel line trapezoid problem (Count Number of Trapezoids I)
        for(auto &p : slopeToIntercept) {
            map<float,int> interceptMap; // intercept --> count

            for(float intercept : p.second) {
                interceptMap[intercept]++;
            }

            // cout << "Slope is : " << p.first << endl;
            int prevHorizontalLines = 0;

            for(auto &it : interceptMap) {
                int count = it.second;
                // cout << "count is : " << count << endl;
                res += count * prevHorizontalLines;
                prevHorizontalLines += count;
            }

        }

        // Subtract parallelogram overcounts
        for(auto &it : midToSlope) {
            if(it.second.size() <= 1) continue;

            map<float,int> mp; // slope ---> count

            for(float slope : it.second) mp[slope]++;

            int prevHorizontalLines = 0;

            for(auto it : mp) {
                int count = it.second;
                res -= count * prevHorizontalLines;
                prevHorizontalLines += count;
            }
        }

        return res;
    }
};  

// y1 = m*x1 + c;
// c = y1 - (m * x1)

// 3 ---> -9 --> 1
// 5 ---> -13 --> 1
// INT_MAX --> 3 -> 1
//        |--> 2 -> 1
// -3 --> 9 --> 1
// 