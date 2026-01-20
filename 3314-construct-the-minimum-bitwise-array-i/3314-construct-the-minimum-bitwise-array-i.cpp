class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            for(int bit = 0; bit < 32; bit++) {
                bool isBitSet = num & (1 << bit);

                if(!isBitSet) { // pehla zero mila
                    if(bit > 0) ans[i] = num & ~(1 << bit-1);
                    else ans[i] = -1;
                    break;
                }
            }
        }

        return ans;
    }
};