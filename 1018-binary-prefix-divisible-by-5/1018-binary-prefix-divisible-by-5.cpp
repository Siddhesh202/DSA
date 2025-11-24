class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0, n = nums.size();
        vector<bool> ans;

        for(int i = 0; i < n; i++) {
            int lbit = nums[i];
            num = ((num << 1) | lbit) % 5;
            ans.push_back(num == 0);
        }

        return ans;
    }
};

// 5 -  101
// 10 - 1010
// 15 - 1111
// 20 - 10100
// 25 - 11001
// 30 - 11110
// 35 - 100011