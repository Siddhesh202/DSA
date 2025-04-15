#define ll long long
class Solution {
public:
    int n;
    void buildTree(vector<ll>& segTree, vector<int>& nums, int i, int l, int r) {
        if(l == r) {
            segTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        
        buildTree(segTree, nums, 2*i+1, l, mid);
        buildTree(segTree, nums, 2*i+2, mid+1, r);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void updateTree(vector<ll> &segTree, int idx, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) { // go left
            updateTree(segTree, idx, val, 2*i+1, l, mid);
        } 
        else {
            updateTree(segTree, idx, val, 2*i+2, mid+1, r);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    ll query(vector<ll> &segTree, int qstart, int qend, int i, int l, int r) {
        if(qend < l || qstart > r) return 0;
        if(l >= qstart && r <= qend) return segTree[i];

        int mid = l + (r - l) / 2;
        return query(segTree, qstart, qend, 2*i+1, l, mid) + query(segTree, qstart, qend, 2*i+2, mid+1, r);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        ll ans = 0;
        map<int,int> mp;
        vector<ll> segTree(4*n, 0);

        // create map for nums2
        for(int i = 0; i < n; i++) mp[nums2[i]] = i;

        updateTree(segTree, mp[nums1[0]], 1, 0, 0, n-1);
    
        for(int i = 1; i < n; i++) {
            int idx = mp[nums1[i]];
            ll leftCommonCount = query(segTree, 0, idx, 0, 0, n-1);
            ll leftUncommonCount = i - leftCommonCount;
            ll rightCnt = n - 1 - idx;
            ll rightCommonCount = rightCnt - leftUncommonCount;
            ans += (leftCommonCount * rightCommonCount);
            updateTree(segTree, idx, 1, 0, 0, n-1);
        }

        return ans;
    }
};