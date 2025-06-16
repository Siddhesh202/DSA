class Solution {
public:
    const int MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> freqPrev, freqNext, temp;
        int n = nums.size(), ans = 0;
        temp[nums[0]]++;

        for(int i = 1; i < n-1; i++) {
            freqPrev[i] = temp.count(nums[i]*2) ? temp[nums[i]*2] : 0;
            temp[nums[i]]++;
        }

        temp.clear();
        temp[nums[n-1]]++;
        for(int i = n-2; i > 0; i--) {
            freqNext[i] = temp.count(nums[i]*2) ? temp[nums[i]*2] : 0;
            temp[nums[i]]++;
        }


        for(int j = 1; j < n-1; j++) {
            ans = (ans + ((1LL * freqPrev[j] * freqNext[j]) % MOD)) % MOD;
        }

        return ans;
    }
};