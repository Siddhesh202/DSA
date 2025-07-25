class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxNeg = INT_MIN;
        set<int> st;
        int sum = 0;

        for(auto &num : nums) {
            if(num < 0) {
                maxNeg = max(maxNeg, num);
            }
            else if(st.find(num) == st.end()) {
                st.insert(num);
                sum += num;
            }
        }

        if(st.empty()) return maxNeg;

        return sum;
    }
};