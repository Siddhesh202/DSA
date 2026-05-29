class Solution {
public:
    int calcSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n%10;
            n /= 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;

        for(auto &num : nums) mini = min(mini, calcSum(num));

        return mini;
    }
};