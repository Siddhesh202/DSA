class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffarr(n, 0);

        for(int i = 0; i < queries.size(); i++) {
            int s = queries[i][0];
            int e = queries[i][1];

            diffarr[s] += 1;
            if(e+1 < n) diffarr[e+1] -= 1; 
        }

        // calclate cumlative sum
        for(int i = 1; i < n; i++) {
            diffarr[i] += diffarr[i-1];
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] > diffarr[i]) return false;
        }

        return true;
    }
};