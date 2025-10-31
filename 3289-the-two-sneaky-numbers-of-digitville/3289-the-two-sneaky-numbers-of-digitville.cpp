class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto num : nums) {
            if(mp.find(num) != mp.end())
            {
                ans.push_back(num);
            }else
                mp[num]++;
        }

        return ans;
    }
};