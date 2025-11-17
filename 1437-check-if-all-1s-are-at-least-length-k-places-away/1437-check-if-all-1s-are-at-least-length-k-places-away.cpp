class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1 && lastOne >= 0 && (i-lastOne-1) < k) return false;

            if(nums[i] == 1) lastOne = i;
        }

        return true;
    }
};