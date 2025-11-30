class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int tar = 0;
        for(int j = 0; j < n; j++) tar = (tar + nums[j]) % p;
        if(tar%p == 0) return 0;

        int curr = 0;
        int ans = n;
        unordered_map<int,int> mp;  // < prefixSum, index >

        mp[0] = -1;

        for(int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;
            int remain = (curr - tar + p) % p;

            if(mp.find(remain) != mp.end()) {
                int len = j - mp[remain];
                ans = min(len, ans);
            }

            mp[curr] = j;
        }

        if(ans == n) return -1;
        return ans;
    }
};