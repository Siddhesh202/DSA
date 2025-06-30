class Solution {
public:
    int findLHS(vector<int>& nums) {
       unordered_map<int,int> mp;
       int ans = 0;

       for(auto &num : nums) {
            mp[num]++;
        }

        for(auto &p : mp) {
            int num = p.first;
            int numfreq = p.second;

            if(mp.count(num+1)) {
                ans = max(ans, mp[num+1]+numfreq);
            }
        } 

        return ans;
    }
};

/* 1 -> 1
   2 -> 3
   3 -> 2
   5 -> 1
   7 -> 1
*/