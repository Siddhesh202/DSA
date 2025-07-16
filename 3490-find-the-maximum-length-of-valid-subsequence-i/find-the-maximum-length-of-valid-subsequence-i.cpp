class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCnt = 0, oddCnt = 0;

        for(auto &num : nums) {
            if(num % 2 == 0) evenCnt++;
            else oddCnt++;
        }

        int alternating = 1;
        int parity = nums[0] % 2;

        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            int currentParity = num % 2;

            if(currentParity != parity) {
                alternating++;
                parity = currentParity;
            }
        }

        return max({evenCnt, oddCnt, alternating});
    }
};