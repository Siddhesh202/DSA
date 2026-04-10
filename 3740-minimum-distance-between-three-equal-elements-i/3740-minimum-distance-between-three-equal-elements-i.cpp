class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            mp[num].push_back(i);
        }

        for(const auto& [key, arr] : mp) {
            int n = arr.size();
            if(n >= 3) {
                for(int i = 0; i < n-2; i++) {
                    for(int j = i+1; j < n-1; j++) {
                        for(int k = j+1; k < n; k ++) 
                            ans = min(ans, abs(arr[i]-arr[j]) + abs(arr[j]-arr[k]) + abs(arr[k]-arr[i]));
                    }
                }
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};