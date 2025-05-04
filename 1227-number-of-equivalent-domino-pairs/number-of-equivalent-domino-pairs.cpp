class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mp(100, 0);
        int ans = 0;

        for(auto &domino : dominoes) {
            if(domino[0] > domino[1]) {
                swap(domino[0], domino[1]);
            }

            int no = domino[0] * 10 + domino[1];
            ans += mp[no];
            mp[no]++;
        }

        return ans;
    }
};