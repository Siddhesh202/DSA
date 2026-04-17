class Solution {
public:
    int formReverse(int num) {
        int ans = 0;

        while(num > 0) {
            int dig = num % 10;
            num /= 10;
            ans = (ans*10) + dig;
        }

        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size(), ans = INT_MAX;

        for(int i = n-1; i >= 0; i--) {
            int no = nums[i];
            int rev = formReverse(nums[i]);

            if(mp.count(rev)) {
                ans = min(ans, abs(i-mp[rev]));
            }

            mp[no] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

