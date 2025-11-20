class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int first, second, ans = 0, n = intervals.size();

        // Sort based on ending
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        first = intervals[0][1] - 1; //r-1
        second = intervals[0][1]; // r
        ans = 2;

        for(int i = 1; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if(l > second) { // No overlap possible
                first = r-1;
                second = r;
                ans += 2;
            }
            else if(l > first) { // take only one point
                first = second;
                second = r;
                ans += 1;
            }
        }

        return ans;
    }
};