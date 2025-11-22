class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for(auto &num : nums) {
            int opt1 = num % 3;
            int opt2 = 3 - opt1;

            if(opt1 < opt2) ans += opt1;
            else ans += opt2;
        }

        return ans;
    }
};