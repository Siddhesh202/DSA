class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pos(32, -1);

        for(int i = n-1; i >= 0; i--) {
            int num = nums[i];
            int maxi = i;
            for(int j = 0; j < 32; j++) {
                if((1 << j) & num) { // jth bit is set in curr element
                    pos[j] = i;
                }
                maxi = max(maxi, pos[j]);
            }

            res[i] = maxi - i + 1;
        }

        return res;
    }
};