class Solution {
public:
    vector<int> segTree;

    void buildTree(vector<int> &baskets, int i, int l, int r) {
        if(l == r) {
            segTree[i] = baskets[l];
            return;
        }

        int mid = (l + r) / 2;
        buildTree(baskets, 2*i+1, l, mid);
        buildTree(baskets, 2*i+2, mid+1, r);

        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    } 

    int search(int i, int l, int r, int k) {
        if(segTree[i] < k) return -1;

        if(l == r) {
            segTree[i] = -1;
            return l;
        }

        int mid = (l + r) / 2;
        int pos = (segTree[2*i+1] >= k) ? search(2*i+1, l, mid, k) : search(2*i+2, mid+1, r, k);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return pos;
    } 

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size(), unplaced = 0;
        segTree.assign(4*n, 0);
        buildTree(baskets, 0, 0, n-1);
        
        for(auto &fruit: fruits) {
            if(search(0, 0, n-1, fruit) == -1)
                unplaced++;
        }

        return unplaced;
    }
};