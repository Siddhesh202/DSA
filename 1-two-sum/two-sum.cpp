class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp; // num, idx

        for(int i = 0; i < nums.size(); i++) {
            int seen = target - nums[i];

            if(mp.count(seen)) {
                ans.push_back(mp[seen]);
                ans.push_back(i);
                break;
            }
            else
                mp[nums[i]] = i;
        }
        return ans;
    }
};