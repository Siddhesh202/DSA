class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,int> mp;

        for(auto &num : nums) mp[num]++;

        for(auto &p : mp) {
            int num = p.first;
            int freq = p.second;

            if(freq == n) return num;
        }

        return -1;
    }
};