#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0, cumSum = 0;
        unordered_map<int, int> freq;
        map<int,int> diffMap;

        int maxi = *max_element(nums.begin(), nums.end());

        for(auto &num : nums) {
            freq[num]++;
            int li = max(0, num-k);
            int ri = min(maxi, num+k);

            diffMap[li] += 1;
            diffMap[ri+1] -= 1;
            diffMap[num] += 0; // Focus
        }

        // iterate on ordered map --> diffArr
        for(auto &it : diffMap) {
            int i = it.first;
            cumSum += it.second;

            int extra = min(numOperations, cumSum - freq[i]);

            ans = max(ans, extra + freq[i]);
        }

        return ans;
    }
};