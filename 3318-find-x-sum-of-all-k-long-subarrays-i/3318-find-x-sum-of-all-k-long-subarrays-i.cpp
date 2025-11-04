class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>& b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
    int xSum(vector<int>& nums, int i, int j, int x) 
    {
        map<int,int, greater<int>> mp;
        vector<pair<int,int>> v;
        int ans = 0;

        for(int k = i; k <= j; k++)
        {
            mp[nums[k]]++;
        }

        for(auto p : mp)
        {
            v.push_back({p.first, p.second});
        }

        sort(v.begin(), v.end(), cmp);

        for(auto p : v)
        {
            if(x > 0) {
                ans += p.first * p.second;
                x--;
            }
        }

        return ans;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int,int> mp;

        vector<int> ans;
        for(int j = 0; j <= k-1; j++) {
            mp[j]++;
        }

        for(int i = 0; (i+k-1) < n; i++) 
        {
            int j = i + k - 1;
            ans.push_back(xSum(nums, i, j, x));
        }
        return ans;
    }
};