class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        int i = 0, j = 0, totalDistElems = 0, n = nums.size(), ans = 0;

        for(auto &num : nums)
            st.insert(num);
        
        totalDistElems = st.size();

        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() == totalDistElems) {
                ans += (n - j);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return ans;
    }
};