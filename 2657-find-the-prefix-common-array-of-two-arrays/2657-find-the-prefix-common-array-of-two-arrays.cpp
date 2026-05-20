class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> arr(51,0);
        vector<int> ans(n, 0);
        int common = 0;

        for(int i = 0; i < n; i++)
        {
            int n1 = A[i];
            int n2 = B[i];

            arr[n1]++;
            arr[n2]++;
            
            if(n1 == n2)
            {
                common++;
                ans[i] = common;
                continue;
            }
            if(arr[n1] == 2)
                common++;
            
            if(arr[n2] == 2)
                common++;
            
            ans[i] = common;
        }

        return ans;
    }
};