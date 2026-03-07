class Solution {
public:
    vector<int> segTree;
    int n;

    void buildTree(int i, int l, int r, vector<int>& arr) {
        if(l == r) {
            segTree[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;
        buildTree(2*i+1, l, mid, arr);
        buildTree(2*i+2, mid+1, r, arr);

        int leftIdx = segTree[2*i+1];
        int rightIdx = segTree[2*i+2];

        if(arr[leftIdx] >= arr[rightIdx]) segTree[i] = leftIdx;
        else segTree[i] = rightIdx;
    }

    int query(int start, int end, int i, int l, int r, vector<int>& arr) {

        if(l > end || r < start) return -1;
        else if(l >= start && r <= end) return segTree[i];
        else {
            int mid = l + (r - l) / 2;
            int leftIdx = query(start, end, 2*i+1, l, mid, arr);
            int rightIdx = query(start, end, 2*i+2, mid+1, r, arr);

            if(leftIdx == -1) return rightIdx;
            if(rightIdx == -1) return leftIdx;

            if(arr[leftIdx] >= arr[rightIdx]) return leftIdx;
            else return rightIdx;
        }
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        vector<int> ans;

        // Build a segment tree on heights
        segTree.assign(4*n, 0);
        buildTree(0, 0, n-1, heights);

        // Iterate over queries
        for(auto &q : queries) {
            int a = min(q[0], q[1]);
            int b = max(q[0], q[1]);

            // if heights[r] > heights[l] then simply put b
            if(a == b) ans.push_back(a);
            else if(heights[a] < heights[b]) ans.push_back(b);

            else { // Isme right hand side par BS + RMIQ laga dena
                int l = b+1;
                int r = n-1;
                int local = -1;
                int target = max(heights[a], heights[b]);
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    int idx = query(l, mid, 0, 0, n-1, heights);

                    if(idx != -1 && heights[idx] > target) {
                        local = idx;
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }

                ans.push_back(local);
            } 
        }

        return ans;
    }
};