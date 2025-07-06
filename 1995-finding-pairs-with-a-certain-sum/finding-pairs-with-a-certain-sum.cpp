class FindSumPairs {
public:
    vector<int> arr1, arr2;
    unordered_map<int,int> mp1, mp2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;

        for(auto &val : arr1) mp1[val]++;
        for(auto &val : arr2) mp2[val]++;
    }
    
    void add(int index, int val) {
        int oldVal = arr2[index];
        int newVal = arr2[index] + val;
        arr2[index] = newVal;
        mp2[newVal]++;
        mp2[oldVal]--;
        if(mp2[oldVal] == 0) mp2.erase(oldVal);
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &it : mp1) {
            int n1 = it.first;
            int f1 = it.second;
            int n2 = tot - n1;

            if(mp2.count(n2)) {
                int f2 = mp2[n2];
                ans += (f1 * f2);
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */