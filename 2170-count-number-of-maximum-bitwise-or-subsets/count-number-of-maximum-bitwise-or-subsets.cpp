#define ll long long
class Solution {
public:
    int n;
    int f(vector<int>& nums, int idx, ll currBitOr, ll maxBitOr) {
        if(idx >= n) {
            return currBitOr == maxBitOr ? 1 : 0;
        }

        int opt1 = f(nums, idx+1, currBitOr, maxBitOr);

        int opt2 = f(nums, idx+1, currBitOr | nums[idx], maxBitOr);

        return opt1 + opt2;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        ll maxBitOr = 0;

        for(auto &num : nums) {
            maxBitOr |= num;
        }

        return f(nums, 0, 0, maxBitOr);
    }
};