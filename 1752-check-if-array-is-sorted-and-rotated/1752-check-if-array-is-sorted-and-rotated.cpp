class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0, i = 0;

        while(i < n) {
            if(nums[i] <= nums[(i+1)%n])
                i++;
            else {
                count++;
                if(count >= 2)
                    return false;
                i++;
            }
        }

        return true;
    }
};