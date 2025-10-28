class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        vector<int> suffixSum(n);
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
                prefixSum[i] = nums[i];
            else
                prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        for(int j = n-1; j >= 0; j--)
        {
            if(j == n-1)
                suffixSum[j] = nums[j];
            else
                suffixSum[j] = nums[j] + suffixSum[j+1];
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                if(prefixSum[i] == suffixSum[i])
                    ans += 2;
                else if(abs(prefixSum[i] - suffixSum[i]) == 1)
                    ans++;
            }
        }

        return ans;
    }
};