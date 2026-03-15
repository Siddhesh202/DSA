class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(auto &num : nums1) mp[num]++;
        for(auto &num : nums2) mp[num]--;

        for(auto &p : mp) {
            int num = p.first;
            int freq = abs(p.second);

            if(freq % 2 != 0) return -1;

            ans += (freq / 2);
        }

        return ans / 2;
    }
};

// nums1 = [10, 10], 10 --> 2
// nums2 = [20, 20], 20 --> -2

