class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        int n = arr.size();

        for(int i = 0; i <= n-3; i++) {
            for(int j = i+1; j <= n-2; j++) {

                if(abs(arr[i] - arr[j]) <= a) {
                    for(int k = j+1; k <= n-1; k++) {
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            ans++;
                    }
                }
            }
        } 

        return ans;
    }
};