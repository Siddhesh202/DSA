class Solution {
public:
    int ans;
    void f(vector<int> &nums, int i, vector<int> output) {
        if(i >= nums.size()) {
            int x = 0;
            for(int i = 0; i < output.size(); i++) {
                x = x ^ output[i];
            }
            ans += x;
            return;
        }

        // notake
        f(nums, i+1, output);

        // take
        output.push_back(nums[i]);
        f(nums, i+1, output);
    }

    int subsetXORSum(vector<int>& nums) {
        ans = 0;
        vector<int> output;
        f(nums, 0, output);
        return ans;    
    }
};