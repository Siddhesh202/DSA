class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0, j = 1, ans = 0;
        int n = nums.size();
        while(j < n-1) {

            if(((nums[i] > nums[j]) && (nums[j+1] > nums[j])) || ((nums[i] < nums[j]) && (nums[j+1] < nums[j]))) {
                ans++;
                i = j;
            }
            j++;
        }

        return ans;
    }
};
