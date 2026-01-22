class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operans = 0;

        while(!is_sorted(nums.begin(), nums.end())) {
            int idx = -1, mini = INT_MAX;

            for(int i = 0; i < nums.size()-1; i++) {
                if(nums[i] + nums[i+1] < mini) {
                    idx = i;
                    mini = nums[i] + nums[i+1];
                }
            }

            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(begin(nums) + idx + 1);
            operans++;
        }

        return operans;
    }
};