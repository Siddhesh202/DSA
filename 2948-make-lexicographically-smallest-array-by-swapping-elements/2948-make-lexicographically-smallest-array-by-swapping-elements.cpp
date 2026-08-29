class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> vec(nums.begin(), nums.end());
        sort(vec.begin(), vec.end());

        // group them
        int groupNum = 0;
        unordered_map<int,int> numToGroup;
        unordered_map<int,list<int>> groupToList;
        numToGroup[vec[0]] = 0;
        groupToList[groupNum].push_back(vec[0]);

        for(int i = 1; i < n; i++)
        {
            if(abs(vec[i] - vec[i-1]) > limit)
                groupNum++;

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        //now iterate over num and get its position
        for(int i = 0; i < n; i++) {
            int grpNo = numToGroup[nums[i]];
            ans[i] = groupToList[grpNo].front();
            groupToList[grpNo].pop_front();
        }

        return ans;
    }
};