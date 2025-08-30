class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        if(n % k != 0) return false;

        // no of groups to be formed
        int grps = n / k;

        for(auto &num : nums) {
            mp[num]++;
            if(mp[num] > grps) return false;
        } 

        return true;
    }
};