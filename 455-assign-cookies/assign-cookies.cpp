class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size(), n = s.size(), ans = 0, i = 0, j = 0;

        while(i < m && j < n) {
            if(g[i] <= s[j]) {
                ans++;
                i++;
            }
            j++;
        }

        return ans;
    }
};