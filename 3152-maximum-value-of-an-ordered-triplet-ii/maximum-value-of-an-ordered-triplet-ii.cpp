#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll ans = INT_MIN;
        vector<int> prefixArr(n,0), suffixArr(n,0);

        prefixArr[0] = nums[0];
        suffixArr[n-1] = nums[n-1];

        for(int j = 1; j < n; j++)
            prefixArr[j] = max(prefixArr[j-1], nums[j-1]);
        
        for(int j = n-2; j >= 0; j--) 
            suffixArr[j] = max(suffixArr[j+1], nums[j+1]);
        
        for(int j = 1; j < n-1; j++) 
            ans = max(ans, (ll) (prefixArr[j] - nums[j]) * suffixArr[j]);

        return ans < 0 ? 0 : ans;
    }
};