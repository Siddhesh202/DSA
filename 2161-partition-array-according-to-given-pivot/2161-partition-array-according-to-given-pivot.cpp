class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);

        // original nums
        int i = 0, j = n-1;

        // result variables
        int _i = 0, _j = n-1;

        while(i < n && j >= 0) {
            if(nums[i] < pivot) {
                res[_i] = nums[i];
                _i++;
            }
            
            if(nums[j] > pivot) {
                res[_j] = nums[j];
                _j--;
            }

            i++;
            j--;
        }

        for(_i; _i <= _j; _i++) {
            res[_i] = pivot;
        }

        return res;
    }
};