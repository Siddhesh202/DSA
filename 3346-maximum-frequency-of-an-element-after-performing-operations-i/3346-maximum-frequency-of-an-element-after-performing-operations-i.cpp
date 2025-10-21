class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxi+1, 0);

        for(auto &num : nums) freq[num]++;

        for(int i = 1; i <= maxi; i++) freq[i] += freq[i-1];

        for(int curr = mini; curr <= maxi; curr++) {
            int freqCurr = freq[curr] - freq[curr-1];
            int l = max(mini, curr-k);
            int r = min(maxi, curr+k);
            int extra = min(numOperations, freq[r] - freq[l-1] - freqCurr);
            ans = max(ans, freqCurr + extra);
        }

        return ans;
    }
};