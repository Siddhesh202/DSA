class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) arr[i] = arr[i-1]+1;
        }

        return arr[n-1];
    }
};

// 1, 1, 2, 2, 2 ----> 1, 1, 2, 2, 2
// 1, 100, 1000  ----> 1, 2, 3