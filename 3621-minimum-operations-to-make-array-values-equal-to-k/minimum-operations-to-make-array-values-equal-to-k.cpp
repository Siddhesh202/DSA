class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < k) return -1;

            st.insert(nums[i]);
        }

        if(*st.begin() == k) return st.size() - 1;

        return st.size();
    }
};