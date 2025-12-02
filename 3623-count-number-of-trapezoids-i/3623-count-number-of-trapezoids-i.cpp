#define ll long long
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        ll res = 0, prevHorizontalLines = 0;

        // {y1 -> 4, y2 -> 3, y3 -> 3}
        for(auto &point : points) {
            mp[point[1]]++;
        }

        for(auto &it : mp) {
            ll count = it.second;

            ll horizontalLines = count * (count - 1) / 2; // nC2

            res += horizontalLines * prevHorizontalLines;

            prevHorizontalLines += horizontalLines;
        }

        return res % 1000000007;
    }
};