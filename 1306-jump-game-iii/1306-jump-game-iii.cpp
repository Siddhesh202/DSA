class Solution {
public:
    int n;

    void dfs(vector<int>& arr, int currIdx, vector<bool> &visited) {
        visited[currIdx] = true;

        // go right if possible
        int rightIdx = currIdx + arr[currIdx];
        if(rightIdx < n && !visited[rightIdx]) dfs(arr, rightIdx, visited);

        // go left if possible
        int leftIdx = currIdx - arr[currIdx];
        if(leftIdx < n && leftIdx >= 0 && !visited[leftIdx]) dfs(arr, leftIdx, visited);

        return;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool> visited(n, 0);

        dfs(arr, start, visited);

        for(int i = 0; i < n; i++) {
            if(arr[i] == 0 && visited[i]) return true;
        }

        return false;
    }
};