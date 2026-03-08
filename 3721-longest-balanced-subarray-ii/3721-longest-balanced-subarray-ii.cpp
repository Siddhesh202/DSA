class Solution {
public:
    vector<int> segMin, segMax, lazy;
    int n, maxL;

    void propogate(int i, int l, int r) {
        if(lazy[i] != 0) {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if(l != r) {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }

            lazy[i] = 0;
        }
    }
    void updateRange(int start, int end, int i, int l, int r, int val) {
        propogate(i, l, r);

        if(l > end || r < start) return;

        if(l >= start && r <= end) {
            lazy[i] += val;
            propogate(i, l, r);
            return;
        }

        int mid = l + (r - l) / 2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int findLeftMostZero(int i, int l, int r) {
        propogate(i, l, r);

        if(segMin[i] > 0 || segMax[i] < 0) return -1;

        if(l == r) return l;

        int mid = l + (r - l) / 2;
        int leftResult = findLeftMostZero(2*i+1, l, mid);

        if(leftResult != -1) return leftResult;

        return findLeftMostZero(2*i+2, mid+1, r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size(), maxL = 0;
        segMin.assign(4*n, 0), segMax.assign(4*n, 0), lazy.assign(4*n, 0);

        //treating even = +1 and odd = -1
        vector<int> cumSum(n, 0);
        unordered_map<int, int> mp;

        for(int r = 0; r < n; r++) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prev = -1;

            if(mp.count(nums[r])) {
                prev = mp[nums[r]];
            }

            if(prev != -1) {
                updateRange(0, prev, 0, 0, n-1, -val);  // [0..prev] we are adding (-val) in the range
            }

            //[0...r] we are adding val in the range
            updateRange(0, r, 0, 0, n-1, val); 
            
            //We are finding left most 0 in the range [0...r]
            int ans = findLeftMostZero(0, 0, n-1);

            if(ans != -1) maxL = max(maxL, r - ans + 1);

            mp[nums[r]] = r;
        }

        return maxL;
    }
};

//  1 2  3 2 4  5  2
// -1 0  0 0 0  0  0  r = 0
//  0 1  0 0 0  0  0  r = 1
// -1 0 -1 0 0  0  0  r = 2
// -1 0  0 1 0  0  0  r = 3
//  0 1  1 2 1  0  0  r = 4
// -1 0  0 2 0 -1  0  r = 5
// -1 0  0 2 1  0  1  r = 6