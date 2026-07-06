class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans = 1;
        for(int i = 1; i < intervals.size(); i++) {
            int a = intervals[i][0], b = intervals[i][1];
            bool isOverlap = false;
            for(int j = 0; j < i; j++) {
                int c = intervals[j][0], d = intervals[j][1];

                // check for overlapping
                if(c <= a && b <= d) { isOverlap = true; break; }
            }

            ans += (!isOverlap);
        }

        return ans;
    }
};