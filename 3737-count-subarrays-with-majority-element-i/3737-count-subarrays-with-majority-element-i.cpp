class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            int count_tar = 0;
            
            for(int j = i; j < n; j++) {
                count_tar += (nums[j] == target);
                int size = j-i+1;
                if(count_tar > (size / 2)) ans++;
            }
        }

        return ans;
    }
};

// eg: [1, 2, 3, 2, 5, 6, 7, 2, 2, 2]
// subarr of size k
// count(target) > k/2 for k sized subarr
// sub arr size = 0 .. n