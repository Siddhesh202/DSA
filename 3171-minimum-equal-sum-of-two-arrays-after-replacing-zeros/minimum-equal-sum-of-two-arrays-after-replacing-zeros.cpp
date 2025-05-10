#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for(auto &num : nums1) {
            if(num == 0) {
                sum1 += 1;
                zero1++;
            }else
                sum1 += num;
        }

        for(auto &num : nums2) {
            if(num == 0) {
                sum2 += 1;
                zero2++;
            }else
                sum2 += num;
        }

        if(sum1 < sum2 && zero1 == 0) return -1;
        if(sum2 < sum1 && zero2 == 0) return -1;
        return max(sum1, sum2);
    }
};