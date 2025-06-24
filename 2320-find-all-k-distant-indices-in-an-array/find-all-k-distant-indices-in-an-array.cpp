class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int lidx = max(0, i-k);
                int ridx = min(n-1, i+k);

                for(int i = lidx; i <= ridx; i++)
                    st.insert(i);
            }
        }

        vector<int> ans(st.begin(), st.end());

        return ans;
    }
};