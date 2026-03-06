class NumArray {
public:
    vector<int> segTree, arr;
    int n;

    void buildTree(int i, int l, int r) {
        if(l == r) {
            segTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildTree(2*i+1, l, mid);
        buildTree(2*i+2, mid+1, r);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void update(int i, int l, int r, int idx, int val) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) update(2*i+1, l, mid, idx, val);
        else update(2*i+2, mid+1, r, idx, val);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int query(int start, int end, int i, int l, int r) {

        if(l > end || r < start) return 0;
        else if(l >= start && r <= end) return segTree[i];
        else {
            int mid = l + (r - l) / 2;
            return query(start, end, 2*i+1, l, mid) + query(start, end, 2*i+2, mid+1, r);
        }
    }

    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        segTree.assign(4*n, 0);
        buildTree(0, 0, n-1);
    }
    
    void update(int index, int val) {
        update(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */