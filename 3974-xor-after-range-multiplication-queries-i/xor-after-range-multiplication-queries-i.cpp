#define ll long long
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        for(auto &query : queries) {
            int li = query[0], ri = query[1], k = query[2], v = query[3];

            while(li <= ri && li < nums.size()) {
                int ans = (nums[li] * 1LL * v) % (1000000007);
                nums[li] = ans;
                li += k;
            }
        }

        for(auto &num : nums) ans ^= num;

        return ans;
    }
};